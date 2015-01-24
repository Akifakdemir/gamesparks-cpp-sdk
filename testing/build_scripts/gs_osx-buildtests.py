
import subprocess
import os
import sys
import shutil
import glob

configurations = ['Debug', 'Release']

cmake_generators = (
	# cmake generator  ,  OS , Architectures, Optional flag
	('Xcode', 'IOS', 'armv64 armv7s armv7', '-iphoneos', ['-sdk', 'iphoneos']),
	('Xcode', 'IOS', 'x86_64 i386', '-iphonesimulator', ['-sdk', 'iphonesimulator']),
	('Xcode', 'OSX', 'x86_64 i386', '', []),
)

def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

def remove_folder(location):
	if os.path.exists(location):
		shutil.rmtree(location)

def generate_and_build_gtest():
	print('build gtest')
	# remove the old version first
	remove_folder(rel_to_abs(os.path.join('..', 'build', 'dependencies', 'gtest')))

	for generator, target_os, target_arch, output_prefix, additional_flags in cmake_generators:
		project_path = rel_to_abs('..', 'dependencies', 'gtest-1.7.0')

		# define the cmake working directory
		cmake_output_path =  os.path.join(project_path, "output_%(target_os)s" % locals());

		if not os.path.exists(cmake_output_path):
			os.makedirs(cmake_output_path)

		# create the path, where we want to get the compiled libs into
		lib_output_path = rel_to_abs(os.path.join('..', 'build', 'dependencies', 'gtest', target_os))

		if not os.path.exists(lib_output_path):
			os.makedirs(lib_output_path)

		# safe the old working directory
		old_cwd = os.getcwd()

		# change working dir into the path where the cmake file is 
		os.chdir(cmake_output_path)

		# let cmake to its job
		subprocess.check_call( ['cmake', '..', '-G', generator, '-DTARGET_ARCH:STRING=%(target_arch)s' % locals(), '-DTARGET_OS:STRING=%(target_os)s' % locals()] )

		for configuration in configurations:
			# xcodebuild -project Gamesparks.xcodeproj -target Gamesparks -configuration RelWithDebInfo -sdk iphoneos || exit $?
			processcall = ['xcodebuild', '-project', 'gtest.xcodeproj', '-target', 'gtest', '-configuration', configuration]

			for additional_flag in additional_flags:
				processcall.append(additional_flag)

			subprocess.check_call( processcall )

			# copy the libs
			libfile = 'libgtest.a'
			conf_lib_dst_folder = os.path.join(lib_output_path, configuration + output_prefix);
			if not os.path.exists(conf_lib_dst_folder):
				os.makedirs(conf_lib_dst_folder)

			# where the lib comes from
			configuration_lib_src = os.path.join(cmake_output_path, configuration + output_prefix, libfile)
			# where it goes
			configuration_lib_dst = os.path.join(conf_lib_dst_folder, libfile)
			shutil.copy(configuration_lib_src, configuration_lib_dst)

		# reset the working directors
		os.chdir(old_cwd)

def create_fat_binary(new_path, new_name, libs_to_merge):
	if not os.path.exists(new_path):
			os.makedirs(new_path)

	process_call = ['lipo', '-create']

	for lib in libs_to_merge:
		process_call.append(lib)

	process_call.append('-output')
	process_call.append(os.path.join(new_path, new_name))

	subprocess.check_call( process_call )

def create_fat_binaries_for_ios():
	ios_binary_root = rel_to_abs(os.path.join('..', 'build', 'dependencies', 'gtest', 'IOS'))
	ios_binaries_debug = os.path.join(ios_binary_root, 'Debug')
	ios_binaries_release = os.path.join(ios_binary_root, 'Release')
	ios_binaries_iphonos_debug = os.path.join(ios_binary_root, 'Debug-iphoneos', )
	ios_binaries_iphonos_debug_lib = os.path.join(ios_binaries_iphonos_debug, 'libgtest.a')
	ios_binaries_iphonsimulator_debug = os.path.join(ios_binary_root, 'Debug-iphonesimulator')
	ios_binaries_iphonsimulator_debug_lib = os.path.join(ios_binaries_iphonsimulator_debug, 'libgtest.a')
	ios_binaries_iphonos_release = os.path.join(ios_binary_root, 'Release-iphoneos')
	ios_binaries_iphonos_release_lib = os.path.join(ios_binaries_iphonos_release, 'libgtest.a')
	ios_binaries_iphonsimulator_release = os.path.join(ios_binary_root, 'Release-iphonesimulator')
	ios_binaries_iphonsimulator_release_lib = os.path.join(ios_binaries_iphonsimulator_release, 'libgtest.a')

	create_fat_binary(ios_binaries_debug, 'libgtest.a', [ios_binaries_iphonos_debug_lib, ios_binaries_iphonsimulator_debug_lib])
	create_fat_binary(ios_binaries_release, 'libgtest.a', [ios_binaries_iphonos_release_lib, ios_binaries_iphonsimulator_release_lib])

	remove_folder(ios_binaries_iphonos_debug)
	remove_folder(ios_binaries_iphonsimulator_debug)
	remove_folder(ios_binaries_iphonos_release)
	remove_folder(ios_binaries_iphonsimulator_release)


def generate_and_build_tests_for_osx():
	# build the tests
	for generator, target_os, target_arch, output_prefix, additional_flags in cmake_generators:
		project_path = rel_to_abs('..', 'build', 'xcode_files_' + target_os + output_prefix)

		# iOS has an pre made solution, because cmake is unable to create cocoa test bundles
		if target_os == 'IOS':
			continue

		old_cwd = os.getcwd()

		if not os.path.exists(project_path):
			os.makedirs(project_path)

		print('chdir: %(project_path)s' % locals())
		os.chdir(project_path)

		subprocess.check_call( ['cmake', '../../build_scripts', '-G', generator, '-DTAG:STRING=%(target_os)s' % locals(), '-DTARGET_ARCH:STRING=%(target_arch)s' % locals(), '-DTARGET_OS:STRING=%(target_os)s' % locals()] )
		
		#for toolset in toolsets:
		for configuration in configurations:
			
			processcall = ['xcodebuild', '-project', 'Project.xcodeproj', '-alltargets', '-configuration', configuration]

			for additional_flag in additional_flags:
				processcall.append(additional_flag)

			subprocess.check_call( processcall )

			# copy the binaries into a more meaningful folder
			copy_from = os.path.join(project_path, configuration, "*")
			copy_to = rel_to_abs('..' , 'tests', target_os, configuration)

			print(copy_to)
			if not os.path.exists(copy_to):
				os.makedirs(copy_to)

			for file in glob.glob(copy_from):
				shutil.copy(file, copy_to)

		# set back the working folder
		os.chdir(old_cwd)

def generate_and_build_tests_for_ios():
	subprocess.check_call(['python','gs_ios-update_testproject.py'])

# cp850
def main():
	# build gtest
	generate_and_build_gtest()
	# merge the ios lib
	create_fat_binaries_for_ios()
	# build the tests
	generate_and_build_tests_for_osx()
	generate_and_build_tests_for_ios()

if __name__ == '__main__':
	main()
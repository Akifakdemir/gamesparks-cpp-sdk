from _winreg import *
import subprocess
import os
import sys
import shutil
import glob

configurations = ['Debug', 'Release']

remove_intermediate_folders = False

cmake_generators = (
	# cmake generator  ,  directory_tag
	('Visual Studio 12'      , 'win32_vs2013'),
	('Visual Studio 12 Win64', 'win64_vs2013'),
)

os.environ['PATH'] += os.pathsep + 'c:/mgames/cmake-3.1.0-rc2-win32-x86/bin/'

def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

def find_msbuild_versions():
	aReg = ConnectRegistry(None, HKEY_LOCAL_MACHINE)

	aKey = OpenKey(aReg, r'SOFTWARE\Microsoft\MSBuild\ToolsVersions')
	for i in range(1024):
		try:
			msbuild_version=EnumKey(aKey, i)
			asubkey=OpenKey(aKey, msbuild_version)
			path=QueryValueEx(asubkey, "MSBuildToolsPath")

			for j in range(1024):
				try:
					vs_version=EnumKey(asubkey, j)
					yield vs_version, msbuild_version, path[0]
				except EnvironmentError:
					break
		except EnvironmentError:
			break


def remove_folder(location):
	if os.path.exists(location):
		shutil.rmtree(location)

def build_with_msbuild(solutionfile, configuration):
	# selection of correct version of msbuild is currently broken if you have several flavours of VS istalled.
	# If the build fails, try to change ms_build_to_use
	ms_build_to_use = -1

	path_to_latest_msbuild = list(find_msbuild_versions())

	path_to_latest_msbuild.sort(lambda x, y: cmp(float(y[0])*100+float(y[1]), float(x[0])*100+float(x[1])))
	path_to_latest_msbuild = path_to_latest_msbuild[ms_build_to_use][-1]
	msbuild_exe = os.path.join(path_to_latest_msbuild, 'msbuild.exe')

	cmd = [
		msbuild_exe,
		'/nologo',
		solutionfile,
		#'/target:All',
		#'/t:rebuild',
		#'/p:PlatformToolset=%(toolset)s' % locals(),
		'/property:Configuration=%(configuration)s' % locals(),
	]

	print(cmd)
	subprocess.check_call(cmd)

def generate_and_build_gtest():
	# remove the old version first
	remove_folder(rel_to_abs(os.path.join('..', 'build', 'dependencies', 'gtest')))
	# build for each generator
	for generator, tag in cmake_generators:
		project_path = rel_to_abs('..', 'dependencies', 'gtest-1.7.0')

		# define the cmake working directory
		cmake_output_path =  os.path.join(project_path, "output_%(tag)s" % locals());

		if not os.path.exists(cmake_output_path):
			os.makedirs(cmake_output_path)

		# safe the old working directory
		old_cwd = os.getcwd()
		# change working dir into the path where the cmake file is 
		os.chdir(cmake_output_path)
		# let cmake to its job
		subprocess.check_call( ['cmake', '..', '-G', generator, '-DTARGET_OS:STRING=Windows'] )

		# create the path, where we want to get the compiled libs into
		lib_output_path = rel_to_abs(os.path.join('..', '..', '..', 'build', 'dependencies', 'gtest', tag))

		if not os.path.exists(lib_output_path):
			os.makedirs(lib_output_path)

		# now lets build for each configuration (Debug, Release, etc...)
		for configuration in configurations:
			# compile 
			build_with_msbuild('gtest.sln', configuration)
		
			# copy the libs
			libfile = 'gtest.lib'
			conf_lib_dst_folder = os.path.join(lib_output_path, configuration);
			if not os.path.exists(conf_lib_dst_folder):
				os.makedirs(conf_lib_dst_folder)

			# where the lib comes from
			configuration_lib_src = os.path.join(cmake_output_path, configuration, libfile)
			# where it goes
			configuration_lib_dst = os.path.join(conf_lib_dst_folder, libfile)
			shutil.copy(configuration_lib_src, configuration_lib_dst)

		# reset the working directors
		os.chdir(old_cwd)

		# remove the intermediate folder
		if remove_intermediate_folders:
			remove_folder(cmake_output_path)

def generate_and_build_tests():
	# build the tests
	for generator, tag in cmake_generators:
		project_path = rel_to_abs('..', 'build', 'visual_studio_project_files_%(tag)s' % locals())

		old_cwd = os.getcwd()

		if not os.path.exists(project_path):
			os.makedirs(project_path)

		print('chdir: %(project_path)s' % locals())
		os.chdir(project_path)

		subprocess.check_call( ['cmake', '../../build_scripts', '-G', generator, '-DTARGET_OS:STRING=Windows', '-DTAG:STRING=%(tag)s' % locals()], stdout=subprocess.PIPE )

		#for toolset in toolsets:
		for configuration in configurations:
			print(configuration)
			build_with_msbuild('Project.sln', configuration)

			# copy the binaries into a more meaningful folder
			copy_from = os.path.join(project_path, configuration, "*.*")
			copy_to = rel_to_abs('..', 'tests', tag, configuration)

			if not os.path.exists(copy_to):
				os.makedirs(copy_to)

			for file in glob.glob(copy_from):
				shutil.copy(file, copy_to)

		# set back the working folder
		os.chdir(old_cwd)

		# remove the intermediate folder
		if remove_intermediate_folders:
			remove_folder(project_path)

# cp850
def main():
	# build gtest
	generate_and_build_gtest()
	# build the tests
	generate_and_build_tests()

if __name__ == '__main__':
	main()
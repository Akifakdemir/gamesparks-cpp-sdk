from _winreg import *
import subprocess
import os
import sys
import shutil

from gs_create_dist_packages import rel_to_abs

os.environ['PATH'] += os.pathsep + 'c:/mgames/cmake-3.1.0-rc2-win32-x86/bin/'

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

toolsets  = ['v110', ]
configurations = ['Debug', 'Release']

cmake_generators = (
	# cmake generator  ,  directory_tag
	#('Visual Studio 11'      , 'win32_vs2012'),
	#('Visual Studio 11 Win64', 'win64_vs2012'),
	('Visual Studio 12'      , 'win32_vs2013'),
	('Visual Studio 12 Win64', 'win64_vs2013'),
)

# cp850
def main():

	# selection of correct version of msbuild is currently broken if you have several flavours of VS istalled.
	# If the build fails, try to change ms_build_to_use
	ms_build_to_use = -1

	path_to_latest_msbuild = list(find_msbuild_versions())

	path_to_latest_msbuild.sort(lambda x, y: cmp(float(y[0])*100+float(y[1]), float(x[0])*100+float(x[1])))
	path_to_latest_msbuild = path_to_latest_msbuild[ms_build_to_use][-1]
	msbuild_exe = os.path.join(path_to_latest_msbuild, 'msbuild.exe')


	for generator, tag in cmake_generators:
		project_path = rel_to_abs('..', 'build', 'visual_studio_project_files_%(tag)s' % locals())

		old_cwd = os.getcwd()

		if not os.path.exists(project_path):
			os.makedirs(project_path)

		os.chdir(project_path)

		subprocess.check_call( ['cmake', '../../build_scripts', '-G', generator] )

		#for toolset in toolsets:
		for configuration in configurations:
			cmd = [
				msbuild_exe,
				'/nologo',
				'Gamesparks.sln',
				'/target:Gamesparks',
				#'/t:rebuild',
				#'/p:PlatformToolset=%(toolset)s' % locals(),
				'/property:Configuration=%(configuration)s' % locals(),
			]

			subprocess.check_call(cmd)

			binary = os.path.join(configuration, 'Gamesparks.lib')

			#dist_directory = rel_to_abs('..', 'build', '%(tag)s_%(toolset)s' % locals())
			dist_directory = rel_to_abs('..', 'build', '%(tag)s' % locals())

			if not os.path.exists(dist_directory):
				os.makedirs(dist_directory)

			binary_target_name = 'Gamesparks.lib'
			if configuration == 'Debug':
				binary_target_name = 'Gamesparks_d.lib'

			binary_target_name = os.path.join(dist_directory, binary_target_name)
			shutil.copy(binary, binary_target_name)

		os.chdir(old_cwd)


if __name__ == '__main__':
	main()
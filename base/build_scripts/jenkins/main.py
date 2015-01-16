#!/usr/bin/python

# jenkins build script for windows

from install_dependencies import install_dependencies
import config
import sys
import os
import subprocess
sys.path.append( os.path.abspath(os.path.join(__file__, '..', '..') ))
from gs_create_dist_packages import main as create_dist_packages

from sys import platform
if platform == 'win32': # win32/win64
	native_script_extension = '.bat'
elif platform == 'darwin':
	native_script_extension = '.sh'
#elif platform in ('linux', 'linux2'):
else:
	raise NotImplementedError('platform %s is currently not supported' % platform)

def build():
	try:
		os.makedirs(config.BUILD_DIR)
	except OSError:
		pass

	try:
		os.makedirs(config.PACKAGING_OUTPUT_DIRECTORY)
	except OSError:
		pass

	os.chdir('..')

	# build new environment for subprocess
	env = os.environ.copy()
	env['PATH'] += os.pathsep + os.path.join(config.CMAKE_ROOT, 'bin')
	env['PATH'] += os.pathsep + config.NDK_ROOT
	env['OUTPUT_DIRECTORY'] = config.BUILD_DIR
	env['PACKAGING_OUTPUT_DIRECTORY'] = config.PACKAGING_OUTPUT_DIRECTORY

	gs_sdk_dist = os.path.abspath(os.path.join(config.BUILD_ROOT, '..', 'gs_sdk-dist'))
	gs_sdk_dist += native_script_extension

	exit_code = subprocess.call([gs_sdk_dist], env=env)
	if exit_code != 0:
		print('=============== BUILD FAILED ===============')
		sys.exit(exit_code)



def main():
	os.chdir(config.BUILD_ROOT)
	install_dependencies()
	build()
	#create_dist_packages(config.PACKAGING_OUTPUT_DIRECTORY)


if __name__ == '__main__':
	main()

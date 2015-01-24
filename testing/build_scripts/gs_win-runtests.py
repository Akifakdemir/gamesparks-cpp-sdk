from _winreg import *
import subprocess
import os
import sys
import shutil
import glob
from array import * 


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


# cp850
def main():
	successful_test = True

	test_path = rel_to_abs('..', 'build', 'tests')

	for generator in os.listdir(test_path):
		generator_path = os.path.join(test_path, generator)

		for configuration in os.listdir(generator_path):
			configuration_path = os.path.join(generator_path, configuration)

			test_files = os.path.join(configuration_path, '*.exe')
			old_cwd = os.getcwd()
			os.chdir(configuration_path)

			for test_file in glob.glob(test_files):
				test_file_base = os.path.basename(test_file)

				print('Start TEST: ' + test_file_base)

				try:
					subprocess.check_call([test_file_base])
				except subprocess.CalledProcessError:
					successful_test = False

			os.chdir(old_cwd)

	if successful_test == False:
		exit(1)

if __name__ == '__main__':
	main()
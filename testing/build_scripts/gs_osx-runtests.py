
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
	('Xcode', 'OSX', 'x86_64 i386', '', []),
)

os.environ['PATH'] += os.pathsep + 'c:/mgames/cmake-3.1.0-rc2-win32-x86/bin/'

def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

def run_osx_tests():
	successful_test = True

	test_path = rel_to_abs('..', 'build', 'tests', 'OSX')

	for generator in os.listdir(test_path):
		generator_path = os.path.join(test_path, generator)

		for configuration in os.listdir(generator_path):
			configuration_path = os.path.join(generator_path, configuration)

			test_files = os.path.join(generator_path, '*')
			old_cwd = os.getcwd()
			os.chdir(generator_path)

			for test_file in glob.glob(test_files):
				test_file_base = os.path.basename(test_file)

				print('Start TEST: ' + test_file_base)

				try:
					subprocess.check_call([os.path.join(generator_path, test_file_base)])
				except subprocess.CalledProcessError:
					successful_test = False

			os.chdir(old_cwd)

	return successful_test


def run_ios_test(test_id):
	successful_test = True
	test_project_root = rel_to_abs('ios_project', 'ALL_TEST_APP')

	old_cwd = os.getcwd()
	os.chdir(test_project_root)

	process_call = [
		'xcodebuild'
		,'test'
		,'-project', 'ALL_TEST_APP.xcodeproj'
		,'-scheme', 'ALL_TEST_STATICLIB'
		,'-destination', 'platform=iOS Simulator,name=iPhone Retina (4-inch),OS=latest'
		,'ACTIVE_TEST_ID=' + str(test_id)]

	try:
		subprocess.check_call(process_call)
	except subprocess.CalledProcessError:
		successful_test = False

	os.chdir(old_cwd)

	return successful_test

def run_ios_tests():
	successful_test = True
	test_files_root = rel_to_abs(os.path.join('..', 'tests', 'base'))
	print(test_files_root)	

	test_id = 1

	for folder in os.listdir(test_files_root):
		test_name = folder

		if test_name == '.DS_Store':
			continue

		if run_ios_test(test_id) != True:
			successful_test = False

		test_id += 1

	return successful_test

# cp850
def main():

	successful_osx_tests = True #run_osx_tests()
	successful_ios_tests = run_ios_tests()

	if successful_osx_tests == False or successful_ios_tests == False:
		exit(1)	

if __name__ == '__main__':
	main()
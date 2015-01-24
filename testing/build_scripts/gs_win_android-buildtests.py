import subprocess
import os
import sys
import shutil
import glob


def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

ndk_build_path = rel_to_abs('..', '..', 'base', 'build_scripts', 'jenkins', 'dependencies', 'android-ndk', 'ndk-build.cmd')

def remove_folder(location):
	if os.path.exists(location):
		shutil.rmtree(location)

def create_folder(location):
	if not os.path.exists(location):
			os.makedirs(location)

def build_with_ndk(jni_folder, relative_project_path_to_jni_folder):
	os.environ['NDK_PROJECT_PATH'] = relative_project_path_to_jni_folder

	process_call = [
		ndk_build_path
		, '--directory=' + jni_folder
		]

	subprocess.check_call(process_call)

def build_gtest_for_android():
	build_with_ndk(os.path.join('..', 'dependencies', 'gtest-1.7.0', 'jni'), os.path.join('..'))


def move_build_results():
	target_path = rel_to_abs('..', 'build', 'dependencies', 'gtest', 'Android')
	src_path = rel_to_abs('..', 'dependencies', 'gtest-1.7.0', 'obj', 'local')
	lib_name = 'libgtest.a'

	remove_folder(target_path)
	create_folder(target_path)

	for folder in os.listdir(src_path):
		files = os.path.join(src_path, folder, '*')
		for sub_file in glob.glob(files):
			if os.path.basename(sub_file) == lib_name:
				architecture_target_path = os.path.join(target_path, folder)
				os.makedirs(architecture_target_path)
				shutil.copy(sub_file, architecture_target_path)
			
def build_tests_for_android():
	template_file = rel_to_abs('jni', 'Android.template.mk')
	generated_file = rel_to_abs('jni', 'Android.mk')
	tests_root = rel_to_abs('..', 'tests', 'base')

	for test in os.listdir(tests_root):
		
		template_content = ''
		with open(template_file, 'r') as myfile:
			template_content = myfile.read()
		
		test_name = test
		include_directories = ''
		src_files = ''

		include_directories = ' "' + os.path.join(tests_root) + '"'

		for test_source_file in glob.glob( os.path.join(tests_root, test, '*.cc')):
			src_files += ' "' + test_source_file.replace('\\', '/') + '"'

		template_content = template_content.replace('{TEST_NAME}', test_name)
		template_content = template_content.replace('{TEST_INCLUDE_DIRECTORIES}', include_directories)
		template_content = template_content.replace('{TEST_SOURCE_FILES}', src_files)

		with open(generated_file, 'w') as myfile:
			myfile.write('%s' % template_content)

		build_with_ndk(os.path.join('jni'), os.path.join('..'))

# cp850
def main():
	build_gtest_for_android()	

	move_build_results()

	build_tests_for_android()


if __name__ == '__main__':
	main()
# This script generates a .cc file for the manually xcode project for the iOS test
import os
import glob

def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

# cp850
def main():
	test_files_root = rel_to_abs(os.path.join('..', 'tests', 'base'))
	template_file = rel_to_abs(os.path.join('ios_project', 'test.template.cc'))
	generated_file = rel_to_abs(os.path.join('ios_project', 'test.cc'))

	template_content = ''
	with open(template_file, 'r') as myfile:
		template_content = myfile.read()

	generated_template = ''

	test_id = 1

	for folder in os.listdir(test_files_root):
		test_folder = os.path.join(test_files_root, folder)
		test_name = folder

		if test_name == '.DS_Store':
			continue

		test_definitions = glob.glob(os.path.join(test_folder, '*.h'))
		test_implementations = glob.glob(os.path.join(test_folder, '*.cc'))

		generated_template += '#if ACTIVE_TEST_ID == ' + str(test_id) + '\n'
		generated_template += '// definitions and implementations for ' + test_name + '\n'

		for definition_file in test_definitions:
			generated_template += '#include "' + definition_file + '"\n'

		for implementation_file in test_implementations:
			generated_template += '#include "' + implementation_file + '"\n'
		
		generated_template += '#endif\n'
		generated_template += '\n'
		test_id += 1

	generated_template = template_content.replace('{0}', generated_template)

	with open(generated_file, 'w') as myfile:
		myfile.write('%s' % generated_template)

	print(generated_template)
	print('template generated')

if __name__ == '__main__':
	main()
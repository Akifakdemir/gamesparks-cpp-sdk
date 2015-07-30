import os
import sys
import subprocess
import platform
import config

def build_and_run_tests():
	TEST_BUILD_DIR = os.path.join(config.BUILD_DIR, 'tests')
	TEST_SRC_DIR = os.path.abspath(os.path.join(config.BUILD_ROOT, '..', '..', '..', 'tests'))

	print TEST_SRC_DIR

	try:
		os.makedirs(TEST_BUILD_DIR)
	except OSError:
		pass

	old_working_directory = os.getcwd()
	os.chdir(TEST_BUILD_DIR)

	generator = {
		'Windows': '-GVisual Studio 12',
		'Darwin': '',
	}[platform.system()]

	subprocess.check_call([
		os.path.join(config.CMAKE_ROOT, 'bin', 'cmake'),
		generator,
		TEST_SRC_DIR
	])

	if platform.system() == 'Windows':

		# query registry for location of msbuild
		out = subprocess.check_output([
			'reg',
			'query',
			r'HKLM\SOFTWARE\Microsoft\MSBuild\ToolsVersions\4.0',
			'/v',
			'MSBuildToolsPath'
		])

		# parse output of msbuild
		out = out.split()
		out = map(str.strip, out) # strip all strings
		out = filter(lambda x: x, out) # filter out empty strings

		print('out is ' + str(out))
		msbuild_path = out[-1]

		print('path to msbuild is: ' + msbuild_path)

		# call msbuild and compile projects in solution
		subprocess.check_call([
			os.path.join(msbuild_path, 'msbuild.exe'),
			'GameSparksTests.sln',
			'/m', # parallel builds
			'/t:GameSparksTests',
			'/p:VisualStudioVersion=12',
		])

		subprocess.check_call([
			'.\\Debug\\GameSparksTests.exe',
			'--gtest_output=xml'
		])
	else:
		subprocess.check_call([
			'make'
		])

		subprocess.check_call([
			'./GameSparksTests',
			'--gtest_output=xml'
		])

	os.chdir(old_working_directory)


def main():
	#if platform.system() != 'Darwin':
	#	raise NotImplementedError('compiling and running tests is not supported on this platform')

	GAMESPARKS_API_KEY = os.environ.get('GAMESPARKS_API_KEY', None)
	GAMESPARKS_API_SECRET = os.environ.get('GAMESPARKS_API_KEY', None)

	if not GAMESPARKS_API_KEY or not GAMESPARKS_API_SECRET:
		print('***************************************************')
		print('***************************************************')
		print('WARNING: not compiling and running tests, because')
		print('the GAMESPARKS_API_KEY and GAMESPARKS_API_SECRET')
		print('environment variables have not been set !')
		print('***************************************************')
		print('***************************************************')
		return

	build_and_run_tests()


if __name__ == '__main__':
	main()

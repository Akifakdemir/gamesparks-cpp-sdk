"""
	This script creates a release and pushes it into the public repository.
	Be carefull when working (and executing) this script, as is discards all
	local changes and untracked files.

	The basic steps are:
		- reset working copy
		- perform some checks
		- clone public repository
		- remove all files in the public repository
		- copy all relevant files from this repository to the public repository
		- add all untracked files in the public repository
		- commit all changes in the public repository
		- commit stages files in the public repository
		- push the public repository
"""
import os
import shutil
import subprocess
import datetime
import platform

ROOT_PATH = os.path.abspath(os.path.join(__file__, '..', '..', '..'))
PUBLIC_REPOSITORY_PATH = os.path.abspath(os.path.join(ROOT_PATH, '..', 'public_repository'))

# setup for quick and dirty testing
import socket
is_running_on_test_machine = socket.gethostname() in ('xim00171.local', 'xim00171.intranet.xoz')

if is_running_on_test_machine:
	print('setting up test environment')

	os.environ['PUBLIC_REPOSITORY_URL'] = os.environ.get('PUBLIC_REPOSITORY_URL', '')
	os.environ['COMMIT_MESSAGE'] = 'release of version %(version)s'
	os.environ['CHANGE_LOG'] = '''
	* new stuff
	* awesome stuff
	* fixed bugs
	* made stuff better
	'''
	os.environ['VERISON_NUMBER_BASE'] = '1.0'


# parameters
PUBLIC_REPOSITORY_URL = os.environ.get('PUBLIC_REPOSITORY_URL', None)
if not PUBLIC_REPOSITORY_URL:
	raise EnvironmentError('You have to specify the PUBLIC_REPOSITORY_URL environment variable')

COMMIT_MESSAGE = os.environ.get('COMMIT_MESSAGE', None)
if not COMMIT_MESSAGE:
	raise EnvironmentError('You have to specify the COMMIT_MESSAGE environment variable')

#CHANGE_LOG = os.environ.get('CHANGE_LOG', None)
#if not CHANGE_LOG:
#	raise EnvironmentError('You have to specify the CHANGE_LOG environment variable')

VERISON_NUMBER_BASE = os.environ.get('VERISON_NUMBER_BASE', None)
if not VERISON_NUMBER_BASE:
	raise EnvironmentError('You have to specify the VERISON_NUMBER_BASE environment variable')



def which(program):
    import os
    def is_exe(fpath):
        return os.path.isfile(fpath) and os.access(fpath, os.X_OK)

    fpath, fname = os.path.split(program)
    if fpath:
        if is_exe(program):
            return program
    else:
        for path in os.environ["PATH"].split(os.pathsep):
            path = path.strip('"')
            exe_file = os.path.join(path, program)
            if is_exe(exe_file):
                return exe_file

    return None


print('====================')
print('git is at ' + (which('git') or which('git.exe')))
print('====================')


def check_git_executable_is_available():
	if not which('git') and not which('git.exe'):
		raise EnvironmentError('git appears to be unavailable, Please install git and add the path to the PATH environment variable.')


def get_commit_number():
	return subprocess.check_output([
		'git',
		'rev-list',
		'HEAD',
		'--count',
	]).strip()
	# git rev-list HEAD --count


def make_version_number():
	return '%s.%s' % ( VERISON_NUMBER_BASE, get_commit_number() )


VERSION_CODE = make_version_number()


def get_git_hashes():
	return subprocess.check_output([
		'git',
		'log',
		"--pretty=format:'%h:%H'",
		'-n',
		'1'
	]).split(':')


def clean_working_copy():
	"""
		reset and clean the working copy into a state "as it would just have been checked out".
	"""
	print('======== Cleaning working copy ...')

	cwd = os.getcwd()
	os.chdir(ROOT_PATH)

	# remove untracked files

	# for some weird reason, git clean always return 1 on windows
	if platform.system() == 'Windows':
		subprocess.call([
			'git',
			'clean',
			'-d',
			'-f',
			'-x',
		])
	else:
		subprocess.check_call([
			'git',
			'clean',
			'-d',
			'-f',
			'-x',
		])

	# reset
	subprocess.check_call([
		'git',
		'reset',
		'--hard',
		'HEAD',
	])

	os.chdir(cwd)


def perform_checks():
	'''
		Check, that we don't have accidentally checked it our credentials.
		Needs manual maintainance.
	'''

	def contains(search_string, path_parts):
		'''
			Checks wether the file located at path_parts contains search_string.
			returns (true/false, full_path)
		'''

		full_path = os.path.join(ROOT_PATH, *path_parts)
		contents = open(full_path).read()
		return search_string in contents, full_path

	def check_does_not_contain_credentials(*path_parts):
		'''
			raise an exception, if the file at path_parts contains the credentials
		'''
		result, full_path = contains(partial_api_key, path_parts)
		if result:
			raise RuntimeError('The file "' + full_path + '" does contain the credentials. Please fix that before creating a release.')

	partial_api_key = '287887K' # we're using the partial API key, not the full one!

	check_does_not_contain_credentials('base', 'samples', 'sample_configuration.h')
	check_does_not_contain_credentials('marmalade', 'sample', 'sample.cpp')
	check_does_not_contain_credentials('cocos2dx', 'Sample', 'Classes', 'AppDelegate.cpp')

	# check wether the creditials for the test repository are still in this file
	result1, full_path = contains(':tra' + 'sh', ('base', 'build_scripts', 'make_release.py'))
	result2, full_path = contains('hA' + '4i', ('base', 'build_scripts', 'make_release.py'))
	result2, full_path = contains('hA' + '4i', ('docs', 'publish_docs.py'))

	if not is_running_on_test_machine and (result1 or result2):
		raise RuntimeError('The file "' + full_path + '" does contain credentials. Please clean up the repository before doing a release.')


def onerror(func, path, exc_info):
    """
    Error handler for ``shutil.rmtree``.

    If the error is due to an access error (read only file)
    it attempts to add write permission and then retries.

    If the error is for another reason it re-raises the error.

    Usage : ``shutil.rmtree(path, onerror=onerror)``
    """
    import stat
    if not os.access(path, os.W_OK):
        # Is the error an access error ?
        os.chmod(path, stat.S_IWUSR)
        func(path)
    else:
        raise


def clone_repository(src_url, dst_path):
	'''
		Clones the public repository and fails spectacularly if the keys have not properly set up
	'''
	print('======== Cloning public repository ...')

	if os.path.exists(dst_path):
		shutil.rmtree(dst_path, onerror=onerror)

	subprocess.check_call([
		'git',
		'clone',
		src_url,
		dst_path
	])


def clone_public_repository():
	clone_repository(PUBLIC_REPOSITORY_URL, PUBLIC_REPOSITORY_PATH)


def clean_public_repository():
	print('======== cleaning public repository =========')
	for root, dirs, files in os.walk(PUBLIC_REPOSITORY_PATH):
		for dir in dirs:
			path = os.path.join(root, dir)
			if '.git' in path:
				continue
			print path


def copy_private_to_public():
	print('======== Copying files from private to public repository ...')


	for root, dirs, files in os.walk(ROOT_PATH):
		for file in files:
			abs_path = os.path.abspath(os.path.join( root, file ))
			if '.git' in abs_path:
				continue

			# dont copy over files that are in subdirectories that start with a dot
			if '/.' in os.path.dirname(abs_path.replace('\\', '/')):
				continue

			# TODO: are those blocks still needed?
			if os.path.join(*('base/build_scripts/jenkins/dependencies'.split('/'))) in abs_path:
				continue

			if '.DS_Store' in abs_path:
				continue

			rel_path = os.path.relpath(abs_path, ROOT_PATH)

			src_path = abs_path
			dst_path = os.path.join(PUBLIC_REPOSITORY_PATH, rel_path)

			dst_dir = os.path.dirname(dst_path)

			if not os.path.exists(dst_dir):
				os.makedirs(dst_dir)

			print(rel_path)
			shutil.copy(src_path, dst_path)


def make_version_header():
	print('======== Creating version header ...')

	GIT_HASH_SHORT, GIT_HASH_LONG = get_git_hashes()
	RELEASE_DATE = datetime.datetime.now()

	vars = dict(globals(), **locals())

	open( os.path.join(PUBLIC_REPOSITORY_PATH, 'base', 'include', 'GameSparks', 'GSVersion.h'), 'wb' ).write('''
/*
	This file was auto generated by %(__file__)s
	Do not modify unless you know what you're doing.
*/

namespace GameSparks
{
	namespace Core
	{
		// anonymous namespace
		namespace
		{
			static const char GS_VERSION_CODE[] = "%(VERSION_CODE)s";
			static const char GS_RELEASE_DATE[] = "%(RELEASE_DATE)s";
			static const char GS_GIT_HASH_SHORT[] = "%(GIT_HASH_SHORT)s";
			static const char GS_GIT_HASH_LONG[] = "%(GIT_HASH_LONG)s";
		}
	}
}
''' % vars)


def commit_and_push(working_copy_path, user_name, user_email, commit_message):
	print('======== Commiting into public repository ...')

	os.chdir(working_copy_path)

	subprocess.check_call([
		'git',
		'config',
		'user.email',
		user_email,
	])

	subprocess.check_call([
		'git',
		'config',
		'user.name',
		user_name,
	])

	subprocess.check_call([
		'git',
		'add',
		'-A'

	])

	subprocess.check_call([
		'git',
		'commit',
		'-a',
		'--author="%(user_name)s <%(user_email)s>"' % locals(),
		'-m',
		commit_message
	])

	subprocess.check_call([
		'git',
		'push',
		'origin',
		'master'
	])


def commit_public_repository():
	commit_and_push(
		PUBLIC_REPOSITORY_PATH,
		'%s Release Bot' % platform.system(),
		'release-bot@gamesparks.com',
		COMMIT_MESSAGE % { 'version' : VERSION_CODE }
	)

def copy_test_results():
	print('copying test results')

	test_result_file = os.path.join(ROOT_PATH, 'base', 'build_scripts', 'jenkins', 'build', 'tests', 'test_detail.xml')
	if os.path.exists(test_result_file):
		dst_path = os.path.join( PUBLIC_REPOSITORY_PATH, 'tests' )
		shutil.copy(test_result_file, dst_path)
	else:
		print('WARNING: test results not found')


def main():
	check_git_executable_is_available()

	clone_public_repository()
	copy_test_results()

	if not is_running_on_test_machine:
		clean_working_copy()

	perform_checks()
	clean_public_repository()
	copy_private_to_public()
	make_version_header()
	commit_public_repository()

if __name__ == '__main__':
	main()




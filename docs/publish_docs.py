#!/usr/bin/python
"""
	This script re-generates the documentation and publishes it to the bitbucket repository.
"""

import os
import sys
import shutil
import platform
from make import main as generate_docs

BASE_PATH = os.path.abspath( os.path.join(__file__, '..', '..') )
print('BASE_PATH = ' + BASE_PATH)


# setup for quick and dirty testing
import socket
is_running_on_test_machine = socket.gethostname() in ('xim00171.local', 'xim00171.intranet.xoz')

if is_running_on_test_machine:
	os.environ['PUBLIC_REPOSITORY_URL'] = 'PUBLIC_REPOSITORY_URL'
	os.environ['DOC_REPOSITORY_URL'] = ''


DOC_REPOSITORY_PATH = os.path.join(BASE_PATH, '..', 'gamesparks_doc_repository')
DOC_REPOSITORY_URL = os.environ.get('DOC_REPOSITORY_URL', '')


if not DOC_REPOSITORY_URL:
	raise EnvironmentError('You have to specify the doc repository URL to publish to')

sys.path.append( os.path.join(BASE_PATH, 'base', 'build_scripts') )

from make_release import VERSION_CODE, check_git_executable_is_available, clone_repository, onerror, commit_and_push

print('VERSION_CODE = ' + VERSION_CODE)


def clone_doc_repository():
	clone_repository(DOC_REPOSITORY_URL, DOC_REPOSITORY_PATH)

def copy_documentation_to_doc_repository():
	shutil.rmtree( os.path.join(DOC_REPOSITORY_PATH, 'cpp-sdk'), onerror=onerror )


	shutil.copytree(
		os.path.join(BASE_PATH, 'docs', 'html'),
		os.path.join( DOC_REPOSITORY_PATH, 'cpp-sdk' )
	)


def commit_doc_repository():
	commit_and_push(
		DOC_REPOSITORY_PATH,
		'Documentation Release Bot on %s' % platform.system(),
		'doc-release-bot@gamesparks.com',
		'Update of documentation for %(version)s' % { 'version' : VERSION_CODE }
	)


def main():
	check_git_executable_is_available()

	print('generating documentation')
	generate_docs()

	clone_doc_repository()
	copy_documentation_to_doc_repository()
	commit_doc_repository()


if __name__ == '__main__':
	main()

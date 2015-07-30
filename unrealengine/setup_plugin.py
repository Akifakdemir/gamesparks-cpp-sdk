#!/usr/bin/python
import shutil
import os
import platform

# taken from gs_create_dist_packages.py
def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

def remove_directory(location):
	if os.path.exists(location):
		shutil.rmtree(location)

# cp850
def main():
	src_dir = rel_to_abs('..', 'base')
	dst_dir = rel_to_abs('plugin', 'GameSparks', 'Source', 'GameSparksBaseSDK')

	remove_directory(dst_dir)

	for directory in ('include', 'src', 'dependencies'):
		shutil.copytree(
			os.path.join(src_dir, directory),
			os.path.join(dst_dir, directory),
		)

	# WP8 is currently not supported by unreal
	remove_directory(os.path.join(dst_dir, 'dependencies', 'openssl', 'libWP8'))
	

if __name__ == '__main__':
	main()

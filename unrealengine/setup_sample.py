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

def remove_folder(location):
	if os.path.exists(location):
		shutil.rmtree(location)

# cp850
def main():
	sample_plugins_folder = rel_to_abs('GameSparksSample', 'Plugins', 'GameSparks')
	remove_folder(sample_plugins_folder)
	shutil.copytree(rel_to_abs('plugin','GameSparks'), sample_plugins_folder)

if __name__ == '__main__':
	main()
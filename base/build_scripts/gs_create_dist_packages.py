#!/usr/binPython
import os
import datetime
import zipfile

BUILD_NUMBER=os.environ.get('BUILD_NUMBER', '_') # <- the underscore is here, so that we can distinguish non-jenkins build

version='0.0.%(BUILD_NUMBER)s' % locals() # TODO: How do we do versioning, where can I get the current version?

def rel_to_abs(*argv):
	'''
		convert the path array given in argv to an absolute path relative to the directory, where this script is located.
		e.g.: if this script is located at /foo/bar/script.py, then rel_to_abs('..', '42') => /foo/42
	'''
	return os.path.abspath(os.path.join(__file__, '..', *argv))

OUTPUT_DIRECTORY = os.environ.get('OUTPUT_DIRECTORY', rel_to_abs('..', 'build')) # output directory of the build steps
HEADER_DIRECTORY = rel_to_abs('..', 'include')
SAMPLE_SIRECTORY = rel_to_abs('..', 'samples')
_PACKAGING_OUTPUT_DIRECTORY = os.environ.get('PACKAGING_OUTPUT_DIRECTORY', rel_to_abs('..', 'dist'))

# directories under build, that should not be packaged
IGNORE_DIRECTORIES=(
	'build',
	'xcode',
	'visual_studio_project_files_win32',
	'visual_studio_project_files_win64'
)

def enumerate_files(root, extensions=[]):
	'''
		recursively yields the absolute paths of all files below root whose lower case extension is in extensions.
		if no extensions are passed, absolute paths of all files below root are yielded.
	'''
	for root, dirs, files in os.walk(root):
		for f in files:
			# filter out files, we don't want to have in our dist package
			if extensions and os.path.splitext(f)[1].lower() not in extensions:
				continue

			path = os.path.abspath(os.path.join(root, f))
			yield path

def clean(PACKAGING_OUTPUT_DIRECTORY):
	print 'removing obsolete packages'
	zips = os.listdir(PACKAGING_OUTPUT_DIRECTORY)
	zips = map(lambda x: os.path.join(PACKAGING_OUTPUT_DIRECTORY, x), zips)
	zips = filter(lambda x: os.path.splitext(x)[-1].lower() == '.zip', zips )
	map(os.unlink, zips)

def main(PACKAGING_OUTPUT_DIRECTORY=_PACKAGING_OUTPUT_DIRECTORY):
	'''
		main packaging routine.

		creates one zipfile with libs, includes and samples for all platforms that can be found below OUTPUT_DIRECTORY (That have been successfully built)
	'''

	print('packaging to "%s"' % PACKAGING_OUTPUT_DIRECTORY)

	# change the working directory to the directory of the script
	my_dir = os.path.abspath(os.path.join(__file__, '..'))
	os.chdir(my_dir)

	time = datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')

	try:
		os.makedirs(PACKAGING_OUTPUT_DIRECTORY)
	except OSError:
		pass

	try:
		os.makedirs(OUTPUT_DIRECTORY)
	except OSError:
		pass

	clean(PACKAGING_OUTPUT_DIRECTORY)

	# get list of platforms that have been built
	platforms = os.listdir(OUTPUT_DIRECTORY)
	platforms = filter(lambda x: os.path.isdir(os.path.join(OUTPUT_DIRECTORY, x)) and x not in IGNORE_DIRECTORIES and 'project_files' not in x, platforms)

	for platform in platforms:
		print('Packaging for platform %s ...' % platform)

		package_name = 'GameSparks-CPP-SDK-%(version)s-%(platform)s-%(time)s' % dict(globals(), **locals())
		zip_file_name = os.path.join(PACKAGING_OUTPUT_DIRECTORY, '%(package_name)s.zip' % locals())
		platform_lib_dir = os.path.join(OUTPUT_DIRECTORY, platform)

		# create zip file from lib and headers
		with zipfile.ZipFile(zip_file_name, 'w') as zf:
			
			# collect library files
			for path in enumerate_files(platform_lib_dir, ['.a', '.so', '.dll', '.lib']):
				arcname = os.path.relpath( path, platform_lib_dir ).replace('\\', '/') # http://www.pkware.com/documents/casestudies/APPNOTE.TXT
				arcname = '%(package_name)s/lib/%(arcname)s' % locals()
				zf.write(path, arcname)

			# collect headers
			for path in enumerate_files(HEADER_DIRECTORY, ['.h']):
				arcname = os.path.relpath( path, HEADER_DIRECTORY ).replace('\\', '/') # http://www.pkware.com/documents/casestudies/APPNOTE.TXT

				# I'd prefer it, if the include files where in a gamesparks subdirectory !
				arcname = '%(package_name)s/include/%(arcname)s' % locals()
				zf.write(path, arcname)

			# collect samples
			for path in enumerate_files(SAMPLE_SIRECTORY, ['.cpp', '.h']):
				arcname = os.path.relpath( path, SAMPLE_SIRECTORY ).replace('\\', '/') # http://www.pkware.com/documents/casestudies/APPNOTE.TXT

				# I'm using the plural here !
				arcname = '%(package_name)s/samples/%(arcname)s' % locals()
				zf.write(path, arcname)

			#collect dependencies
			# TODO

		print('done')

if __name__ == '__main__':
	main()

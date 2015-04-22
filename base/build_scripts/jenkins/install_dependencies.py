import os
import sys
import urllib
import config
import zipfile
import tarfile
import shutil
import subprocess

from sys import platform

android_sdk_version = '24.0.2'

if platform == 'win32': # actually win32 and/or win64
	CMAKE_URL = 'http://www.cmake.org/files/v3.1/cmake-3.1.0-rc3-win32-x86.zip'
	NDK_URL = 'http://dl.google.com/android/ndk/android-ndk-r10d-windows-x86_64.exe'
	ANDROID_SDK_URL = 'http://dl.google.com/android/android-sdk_r' + android_sdk_version + '-windows.zip'
elif platform == 'darwin': #OSX
	CMAKE_URL = 'http://www.cmake.org/files/v3.0/cmake-3.0.2-Darwin64-universal.tar.gz'
	NDK_URL = 'http://dl.google.com/android/ndk/android-ndk-r10c-darwin-x86_64.bin'
	ANDROID_SDK_URL = 'http://dl.google.com/android/android-sdk_r' + android_sdk_version + '-macosx.zip'
#elif platform in ('linux', 'linux2'):
else:
	raise NotImplementedError('platform %s is currently not supported' % platform)

cmake_package = os.path.join(config.BUILD_ROOT, CMAKE_URL.split('/')[-1])
ndk_package = os.path.join(config.BUILD_ROOT, cmake_package.split('/')[-1])
android_sdk_package = os.path.join(config.BUILD_ROOT, ANDROID_SDK_URL.split('/')[-1])


def download(url, destination):
	def reporthook(count, block_size, total_size):
		sys.stdout.write('{3}downloaded {0} bytes of {1} bytes ({2:.1f}%)               '.format(
			count*block_size,
			total_size,
			100.0 * count * block_size / total_size,
			'\r' * 80
		))

	urllib.urlretrieve(url, destination, reporthook)
	print 'download done'

# windows has an restriction about the size of a filename (260)
# the android sdk contains some eclipse files, which are very long
# and cause a extraction error during a simple extraction
# therefore I wrote this function, which extracts the files if possible
def unzip(zip_file_location, extract_location):
	max_path_size = 240
	skipped_files = 0
	with zipfile.ZipFile(zip_file_location, 'r') as zf:
		for archive_member in zf.infolist():
			dst_path = os.path.join(extract_location, archive_member.filename)
			if len(dst_path) > max_path_size:
				skipped_files += 1
				print('skipping: ' + archive_member.filename)
			else:
				print('extract: ' + archive_member.filename)
				zf.extract(archive_member, extract_location)	

	print('skipped files total: ' + str(skipped_files))

#def unzip(package, dst):
#	print('unzipping "%s"' % package)
#	with zipfile.ZipFile(package, 'r') as zf:
#		root_in_zip = zf.namelist()[0].split('/')[0]
#		zf.extractall()
#		shutil.move( root_in_zip, dst)
#	print('[done]')

def untar(package, dst):
	print('untarring "%s"' % package)
	#with tarfile.TarFile(package, 'r') as zf:
	with tarfile.open(package, 'r') as zf:
		root_in_zip = zf.getnames()[0].split('/')[0]
		zf.extractall()
		shutil.move( root_in_zip, dst)
	print('[done]')

def uncompress(package, dst):
	if '.tar' in package:
		untar(package, dst)
	else:
		unzip(package, dst)


def install_cmake():
	if not os.path.exists(os.path.join(config.CMAKE_ROOT, 'cmake.org.html')) and not os.path.exists(os.path.join(config.CMAKE_ROOT, 'Info.plist')):
		if not os.path.exists(cmake_package):
			download(CMAKE_URL, cmake_package)

		uncompress(cmake_package, config.CMAKE_ROOT )
		os.unlink(cmake_package)


def install_ndk():
	if not os.path.exists(os.path.join(config.NDK_ROOT, 'ndk-build')):
		if not os.path.exists(ndk_package):
			download(NDK_URL, ndk_package)

		subprocess.call([ndk_package, '-y'])
		shutil.move('android-ndk-r10d', config.NDK_ROOT)
		os.unlink(ndk_package)


def install_androidsdk():
	if not os.path.exists(os.path.join(config.ANDROID_SDK_ROOT)):
		if not os.path.exists(android_sdk_package):
			download(ANDROID_SDK_URL, android_sdk_package)
		
		uncompress(android_sdk_package, config.ANDROID_SDK_ROOT )
		os.unlink(android_sdk_package)

def install_dependencies():
	install_cmake()
	install_ndk()
	install_androidsdk()

if __name__ == '__main__':
	os.chdir(config.BUILD_ROOT)
	install_dependencies()

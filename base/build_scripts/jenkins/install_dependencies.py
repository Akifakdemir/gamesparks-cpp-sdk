import os
import sys
import urllib
import config
import zipfile
import shutil
import subprocess

from sys import platform

if platform == 'win32': # actually win32 and/or win64
	CMAKE_URL = 'http://www.cmake.org/files/v3.1/cmake-3.1.0-rc3-win32-x86.zip'
	NDK_URL = 'http://dl.google.com/android/ndk/android-ndk-r10d-windows-x86_64.exe'
elif platform == 'darwin': #OSX
	CMAKE_URL = 'http://www.cmake.org/files/v3.0/cmake-3.0.2-Darwin64-universal.tar.gz'
	NDK_URL = 'http://dl.google.com/android/ndk/android-ndk-r10c-darwin-x86_64.bin'
#elif platform in ('linux', 'linux2'):
else:
	raise NotImplementedError('platform %s is currently not supported' % platform)

cmake_package = os.path.join(config.BUILD_ROOT, CMAKE_URL.split('/')[-1])
ndk_package = os.path.join(config.BUILD_ROOT, cmake_package.split('/')[-1])


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


def unzip(package, dst):
	print('unzipping "%s"' % package)
	with zipfile.ZipFile(package, 'r') as zf:
		root_in_zip = zf.namelist()[0].split('/')[0]
		zf.extractall()
		shutil.move( root_in_zip, dst)
	print('[done]')


def install_cmake():
	if not os.path.exists(os.path.join(config.CMAKE_ROOT, 'cmake.org.html')):
		if not os.path.exists(cmake_package):
			download(CMAKE_URL, cmake_package)

		unzip(cmake_package, config.CMAKE_ROOT )
		os.unlink(cmake_package)


def install_ndk():
	if not os.path.exists(os.path.join(config.NDK_ROOT, 'ndk-build')):
		if not os.path.exists(ndk_package):
			download(NDK_URL, ndk_package)

		subprocess.call([ndk_package, '-y'])
		shutil.move('android-ndk-r10d', config.NDK_ROOT)
		os.unlink(ndk_package)


def install_dependencies():
	install_cmake()
	install_ndk()

if __name__ == '__main__':
	os.chdir(config.BUILD_ROOT)
	install_dependencies()

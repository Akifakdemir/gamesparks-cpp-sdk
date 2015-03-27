import os
import sys
import urllib
import zipfile
import shutil
import subprocess

CMAKE_URL = 'http://www.cocos2d-x.org/filedown/cocos2d-x-3.4.zip'
COCOS_ROOT = os.path.abspath(os.path.join(__file__, '..', 'Sample', 'cocos2d'))
cocos_package = os.path.abspath(os.path.join(__file__, '..', CMAKE_URL.split('/')[-1]))


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

def install_cocos():
	if not os.path.exists(os.path.join(COCOS_ROOT, 'AUTHORS')):
		if not os.path.exists(cocos_package):
			download(CMAKE_URL, cocos_package)

		unzip(cocos_package, COCOS_ROOT )
		os.unlink(cocos_package)

def download_cocos_dependencies():
	if os.path.exists(os.path.join(COCOS_ROOT, 'external', 'png')):
		print('skipping installing dependencies')
		return

	cwd = os.getcwd()

	os.chdir( COCOS_ROOT )

	subprocess.check_call([
		'python',
		'./download-deps.py',
		'--remove-download=yes',
	])

	os.chdir(cwd)

if __name__ == '__main__':
	install_cocos()
	download_cocos_dependencies()

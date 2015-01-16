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

def cpy_if_exists(src, dst):
	if os.path.isfile(src):
		shutil.copy(src, dst)

# cp850
def main():
	openssl_path = 'openssl'
	if platform.system().lower() == 'darwin':
		openssl_path = 'openssl-1.0.1j'
	elif platform.system().lower() == 'windows':
		openssl_path = 'openssl'

	plugin_path = rel_to_abs('plugin', 'GameSparks')
	plugin_include_path = os.path.join(plugin_path, 'Source', 'GameSparksBaseSDK', 'include')
	plugin_lib_path = os.path.join(plugin_path, 'Source', 'GameSparksBaseSDK', 'libs')
	plugin_lib_openssl_path = os.path.join(plugin_lib_path, 'openssl')
	plugin_lib_gamesparks_path = os.path.join(plugin_lib_path, 'GameSparks')
	dependency_path = rel_to_abs('..', 'base', 'dependencies')
	dependency_openssl_lib_path = os.path.join(dependency_path, openssl_path)
	sdk_include_path = rel_to_abs('..', 'base', 'include', 'GameSparks')
	sdk_lib_path = rel_to_abs('..', 'base', 'build')

	remove_folder(os.path.join(plugin_path, 'Binaries'))
	remove_folder(os.path.join(plugin_path, 'Source', 'GameSparksBaseSDK'))

	os.makedirs(plugin_include_path)
	os.makedirs(plugin_lib_path)

	# copy GameSparks BASE SDK
	shutil.copytree(sdk_include_path, os.path.join(plugin_include_path, 'GameSparks'))
	shutil.copy(os.path.join(dependency_path, 'cjson', 'cJSON.h'), os.path.join(plugin_include_path, 'cJSON.h'))
	shutil.copytree(os.path.join(dependency_path, 'eastl', 'include'), os.path.join(plugin_include_path, 'eastl', 'include'))

	# create folders for openssl libs
	os.makedirs(os.path.join(plugin_lib_openssl_path, 'libIOS'))
	os.makedirs(os.path.join(plugin_lib_openssl_path, 'libOSX'))
	os.makedirs(os.path.join(plugin_lib_openssl_path, 'libVSWin32'))
	os.makedirs(os.path.join(plugin_lib_openssl_path, 'libVSWin64'))
	os.makedirs(os.path.join(plugin_lib_openssl_path, 'libWP8_ARM'))
	os.makedirs(os.path.join(plugin_lib_openssl_path, 'libWP8_X86'))

	# copy openssl libs for the platforms
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libIOS', 'libcrypto.a'), os.path.join(plugin_lib_openssl_path, 'libIOS', 'libcrypto.a'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libIOS', 'libssl.a'), os.path.join(plugin_lib_openssl_path, 'libIOS', 'libssl.a'))

	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libOSX', 'libcrypto.a'), os.path.join(plugin_lib_openssl_path, 'libOSX', 'libcrypto.a'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libOSX', 'libssl.a'), os.path.join(plugin_lib_openssl_path, 'libOSX', 'libssl.a'))

	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libVSWin32', 'libeay32.lib'), os.path.join(plugin_lib_openssl_path, 'libVSWin32', 'libeay32.lib'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libVSWin32', 'ssleay32.lib'), os.path.join(plugin_lib_openssl_path, 'libVSWin32', 'ssleay32.lib'))

	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libVSWin64', 'libeay32.lib'), os.path.join(plugin_lib_openssl_path, 'libVSWin64', 'libeay32.lib'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libVSWin64', 'ssleay32.lib'), os.path.join(plugin_lib_openssl_path, 'libVSWin64', 'ssleay32.lib'))

	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libWP8', 'libeay32_lib_ARM.lib'), os.path.join(plugin_lib_openssl_path, 'libWP8_ARM', 'libeay32_lib_ARM.lib'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libWP8', 'ssleay32_lib_ARM.lib'), os.path.join(plugin_lib_openssl_path, 'libWP8_ARM', 'ssleay32_lib_ARM.lib'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libWP8', 'libeay32_lib_x86.lib'), os.path.join(plugin_lib_openssl_path, 'libWP8_X86', 'libeay32_lib_x86.lib'))
	cpy_if_exists(os.path.join(dependency_openssl_lib_path, 'libWP8', 'ssleay32_lib_x86.lib'), os.path.join(plugin_lib_openssl_path, 'libWP8_X86', 'ssleay32_lib_x86.lib'))

	# create folders for gamesparks libs
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libIOS'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libOSX'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libVSWin32'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libVSWin64'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libWP8_ARM'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libWP8_X86'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libAndroid_armeabi'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libAndroid_armeabi-v7a'))
	os.makedirs(os.path.join(plugin_lib_gamesparks_path, 'libAndroid_x86'))

	# copy gamesparks libs
	cpy_if_exists(os.path.join(sdk_lib_path, 'iOS_eastl', 'libGamesparks.a'), os.path.join(plugin_lib_gamesparks_path, 'libIOS', 'libGamesparks.a'))
	cpy_if_exists(os.path.join(sdk_lib_path, 'OSX_eastl', 'libGamesparks.a'), os.path.join(plugin_lib_gamesparks_path, 'libOSX', 'libGamesparks.a'))

	cpy_if_exists(os.path.join(sdk_lib_path, 'win32_vs2013', 'Gamesparks.lib'), os.path.join(plugin_lib_gamesparks_path, 'libVSWin32', 'Gamesparks.lib'))
	cpy_if_exists(os.path.join(sdk_lib_path, 'win64_vs2013', 'Gamesparks.lib'), os.path.join(plugin_lib_gamesparks_path, 'libVSWin64', 'Gamesparks.lib'))

	cpy_if_exists(os.path.join(sdk_lib_path, 'Android', 'armeabi', 'libGamesparks.a'), os.path.join(plugin_lib_gamesparks_path, 'libAndroid_armeabi', 'libGamesparks.a'))
	cpy_if_exists(os.path.join(sdk_lib_path, 'Android', 'armeabi-v7a', 'libGamesparks.a'), os.path.join(plugin_lib_gamesparks_path, 'libAndroid_armeabi-v7a', 'libGamesparks.a'))
	cpy_if_exists(os.path.join(sdk_lib_path, 'Android', 'x86', 'libGamesparks.a'), os.path.join(plugin_lib_gamesparks_path, 'libAndroid_x86', 'libGamesparks.a'))


	

if __name__ == '__main__':
	main()

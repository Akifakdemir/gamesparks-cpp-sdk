from install_dependencies import install_cocos, download_cocos_dependencies
import os
import shutil
import subprocess
import platform

BUILD_ROOT = os.path.abspath(os.path.join( __file__, '..', 'Sample', 'proj.ios_mac' ))

def compile_base_sdk():
	if platform.system() == 'Darwin':
		subprocess.check_call([
			'../base/build_scripts/jenkins/main.sh'
		])
	else:
		raise NotImplemented('auto build not supported yet on this platform')
		subprocess.check_call([
			r'..\base\build_scripts\jenkins\main.py'
		])



if __name__ == '__main__':
	#compile_base_sdk()
	install_cocos()
	download_cocos_dependencies()

	current_wd = os.getcwd()

	#try:
	#	os.makedirs(BUILD_ROOT)
	#except OSError:
	#	pass
	#os.chdir(BUILD_ROOT)

	os.chdir(BUILD_ROOT)
	subprocess.check_call([
		'xcodebuild',
		'-target',
		"CocosSample Mac"
	])

	# note: we're just using the cmake installed by compile_base_sdk here	
	#subprocess.check_call([
	#	'../../base/build_scripts/jenkins/dependencies/cmake/bin/cmake',
	#	'-DCMAKE_OSX_SYSROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/',
	#	'-DCMAKE_OSX_DEPLOYMENT_TARGET=10.10',
	#	'../Sample'
	#])

	#subprocess.check_call([
	#	'make'
	#])

	#os.chdir(current_wd)

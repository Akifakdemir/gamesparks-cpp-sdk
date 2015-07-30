#!/usr/bin/python

import subprocess
import platform
import os
from main import main as build_base_sdk
from config import BUILD_DIR

ROOT_PATH = os.path.abspath(os.path.join(__file__, '..', '..', '..', '..'))
UNREAL_BUILD_DIR = os.path.join(BUILD_DIR, 'unreal')
print('UNREAL_BUILD_DIR is ' + UNREAL_BUILD_DIR)

def setup_unreal_sample():
	cwd = os.getcwd()
	os.chdir( os.path.join( ROOT_PATH, 'unrealengine', ) )

	if platform.system() == 'Darwin':
		setup = './setup.sh'
	else:
		setup = 'setup.bat'

	subprocess.check_call([
		setup
	])

	os.chdir( cwd )	

def ue_build(RunUAT, uproject, targetplatform):
	cwd = os.getcwd()
	os.chdir(os.path.dirname(RunUAT))

	subprocess.check_call([
		RunUAT,
		'BuildCookRun',
		'-project="%s"' % uproject.replace('\\', '/'),
		'-noP4',
		'-platform=%s' % targetplatform,
		'-clientconfig=Development',
		'-serverconfig=Development',
		'-cook',
		'-allmaps',
		'-build',
		'-stage',
		'-pak',
		'-archive',
		'-archivedirectory=%s' % os.path.join(UNREAL_BUILD_DIR, 'archive').replace('\\', '/'),
	])

	subprocess.check_call([
		RunUAT,
		'BuildCookRun',
		'-project="%s"' % uproject.replace('\\', '/'),
		'-noP4',
		'-platform=%s' % targetplatform,
		'-clientconfig=Development',
		'-serverconfig=Development',
		'-cook',
		'-allmaps',
		'-NoCompile',
		'-stage',
		'-pak',
		'-archive',
		'-archivedirectory=%s' % os.path.join(UNREAL_BUILD_DIR, 'archive').replace('\\', '/'),
	])

	os.chdir(cwd)

def build_unreal_sample():
	cwd = os.getcwd()

	if not os.path.exists(UNREAL_BUILD_DIR):
		os.makedirs(UNREAL_BUILD_DIR)

	if platform.system() == 'Darwin':
		UNREAL_ENGINE_DIR = '/Users/Shared/UnrealEngine/4.7/'
		RunUAT = os.path.join(UNREAL_ENGINE_DIR, 'Engine/Build/BatchFiles/RunUAT.command')
		targetplatform='Mac'
	else:
		UNREAL_ENGINE_DIR = 'c:/Program Files/Epic Games/4.7/'
		RunUAT = os.path.join(UNREAL_ENGINE_DIR, 'Engine/Build/BatchFiles/RunUAT.bat')
		targetplatform='Win64'

	print("UNREAL_BUILD_DIR="+UNREAL_BUILD_DIR)
	print("UNREAL_ENGINE_DIR="+UNREAL_ENGINE_DIR)
	print("RunUAT="+RunUAT)

	os.chdir( os.path.join(ROOT_PATH, 'unrealengine', 'GameSparksSample') )

	uproject = os.path.join(ROOT_PATH, 'unrealengine', 'GameSparksSample', 'GameSparksSample.uproject')

	# chmod +x /Users/Shared/UnrealEngine/4.7/Engine/Binaries/DotNET/UnrealBuildTool.exe

	# /Users/Shared/UnrealEngine/4.7/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project="GameSparksSample.uproject" -noP4 -platform=Win64 -clientconfig=Development -serverconfig=Development -cook -maps=AllMaps -compile -stage -pak -archive -archivedirectory="Output Directory"

	ue_build(RunUAT, uproject, targetplatform)

	#if targetplatform == 'Mac':
	#	subprocess.check_call([
	#		RunUAT,
	#		'BuildCookRun',
	#		'-nop4',
	#		'-project=%s' % uproject.replace('\\', '/'),
	#		'-CookDir=%s' % os.path.join(UNREAL_BUILD_DIR, 'cook').replace('\\', '/'),
	#		'-archivedirectory=%s' % os.path.join(UNREAL_BUILD_DIR, 'archive').replace('\\', '/'),
	#		'-cook',
	#		'-targetplatform=%s' % 'iOS',
	#		'-utf8output',
	#		'-allmaps',
	#		'-clean',
	#		'-stage',
	#		'-cook',
	#		'-pak',
	#		'-compressed',
	#		'-archive',
	#	])


	'''subprocess.check_call([
		RunUAT,
		'BuildCookRun',
		'-nocompile',
		'-nop4',
		'-project="%s"' % uproject,
		'-cook',
		'-compressed',
		'-allmaps',
		'-stage',
		'-archive',
		'-archivedirectory="%s"' % UNREAL_BUILD_DIR,
		'-package',
		#'-LinuxNoEditor',
		'-clientconfig=Development',
		'-ue4exe=UE4Editor',
		'-clean',
		'-pak',
		'-targetplatform=Mac',
		'-utf8output',
	])'''


	# Mac, Linux, Win64
	'''
	subprocess.check_call([
		RunUAT,
		'BuildCookRun',
		'-project="%s"' % uproject,
		'-noP4',
		'-platform=Mac',
		'-clientconfig=Development',
		'-serverconfig=Development',
		'-cook',
		'-maps=AllMaps',
		'-compile',
		'-stage',
		'-pak',
		'-archive',
		'-archivedirectory="%s"' % UNREAL_BUILD_DIR,
	])
'''

	os.chdir( cwd )

def main():
	#build_base_sdk()
	#setup_unreal_sample()
	build_unreal_sample()

if __name__ == '__main__':
	main()

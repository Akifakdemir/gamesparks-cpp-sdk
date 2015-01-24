#-*- coding:UTF-8
from _winreg import *
import subprocess
import os
import sys
import shutil
import re
from subprocess import Popen, PIPE, STDOUT
import threading
import time

from gs_create_dist_packages import rel_to_abs

android_sdk_tool_path = rel_to_abs('jenkins', 'dependencies', 'android-sdk', 'android-sdk-windows', 'tools')
android_sdk_android_cmd = os.path.join(android_sdk_tool_path, 'android.bat')
android_sdk_emulator_cmd = os.path.join(android_sdk_tool_path, 'emulator-arm.exe')

def setup_avd():
	process_call = [
		android_sdk_android_cmd,
		'create',
		'avd',
		'-n',
		'testing_android',
		'-t',
		'1',
		'--abi',
		'default/armeabi-v7a',
		'--force'
		]

	# start the avd creation
	print(process_call)
	p = Popen(process_call, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
	# we have to answer the hardware question with 'n'
	grep_stdout = p.communicate(input='n\n')
	print(grep_stdout)

import socket

def my_threaded_func():
	process_call = [
		android_sdk_emulator_cmd,
		'-avd',
		'testing_android',
		'-scale',
		'96dpi',
		'-dpi-device',
		'160'
		]

	print(process_call)
	p = Popen(process_call, stdout=PIPE, stdin=PIPE, stderr=STDOUT, shell=True)
	time.sleep(10)
	grep_stdout = p.communicate()
	print('pid: ' + str(p.pid) + ' ' + grep_stdout)

	sock = socket.socket()
	sock.connect(('localhost', 5554))
	sock.recv(1000)
	sock.send('kill\r\n')

def start_eumlator():
	thread = threading.Thread(target=my_threaded_func)
	thread.start()

# cp850
def main():
	setup_avd()	
	start_eumlator()

if __name__ == '__main__':
	main()
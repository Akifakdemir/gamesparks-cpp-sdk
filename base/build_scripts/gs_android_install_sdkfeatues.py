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


android_packages = [
	'tools',
	'platform-tools',
	'build-tools-21.1.2',
	'android-21',
	'sys-img-armeabi-v7a-android-21',
	'sys-img-x86_64-android-21',
	'sys-img-x86-android-21']


def filter_packages(package_id, package_name, package_type, package_desc, package_rev):
	return len(filter(lambda x: x == package_name, android_packages)) > 0 

def print_package(package_id, package_name, package_type, package_desc, package_rev):
	print('id: %(package_id)s name: %(package_name)s' % locals())

def get_required_packages():

	process_call = [
		android_sdk_android_cmd,
		'list',
		'sdk',
		'--all',
		'--extended'
		]

	print('call: %(process_call)s' % locals())
	process_output = subprocess.check_output( process_call )
	# do windows encoding magic
	process_output = process_output.decode("cp1255").encode('utf-8')


	group_name_package_id = 'package_id'
	group_name_package_name = 'package_name'
	group_name_package_type = 'package_type'
	group_name_package_desc = 'package_desc'
	group_name_package_rev = 'package_rev'

	regex_pattern = r'id: (?P<' + group_name_package_id + r'>\d*) or "(?P<' + group_name_package_name + r'>.*)"\n.*Type: (?P<' + group_name_package_type + r'>.*)\n.*Desc: (?P<' + group_name_package_desc + r'>.*)(?:\n.*Revision (?P<' + group_name_package_rev + r'>\d*))?'
	my_regex = re.compile(regex_pattern)

	# select the packages and return them as a list of ids
	# map the match groups into dictionaries 
	extracted_matches = map(lambda x: x.groupdict(), my_regex.finditer(process_output)) 

	# call the filter to get only the packages we are interested in
	# **x unpacks the dictionary into the named parameters  
	return filter(lambda x: filter_packages(**x), extracted_matches)




class Periodic_kill_adb(threading.Thread):
	def __init__(self):
		self.should_run = True
		super(Periodic_kill_adb, self).__init__()
		self.start()

	def signal_quit(self):
		self.should_run = False
		self.join()

	def run(self):
		while self.should_run:
			time.sleep(3.0)
			process_call = [
				'adb',
				'kill-server'
				]

			subprocess.check_call( process_call )
			print(process_call)

# cp850
def main():
	# get the ids of the packages we're looking for
	selected_packages = get_required_packages()

	print('selected packages are:')
	# create the comma separated list of the ids we want to install here
	package_ids = ''
	for package in selected_packages:
		print_package(**package)
		package_ids += package['package_id'] + ','

	# remove the last comma 
	if len(package_ids) > 0:
		package_ids = package_ids[:-1]

	# On systems like Windows 8.1, there could be problem with the default adb server
	# to get the installation done, we need to shutdown the adb server periodically
	# its quite ugly and uncommon
	killer = Periodic_kill_adb()

	process_call = [
		android_sdk_android_cmd,
		'update',
		'sdk',
		'-u',
		'--all',
		'-t',
		package_ids
		]

	# start the final sdk package installation
	print(process_call)
	p = Popen(process_call, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
	# during the installation, we have to accept the licence with 'y'
	grep_stdout = p.communicate(input='y\n')
	print(grep_stdout)
	# when the setup is done, we stop our adb shutdown thread
	killer.signal_quit()


if __name__ == '__main__':
	main()
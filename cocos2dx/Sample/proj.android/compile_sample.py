#!/usr/bin/python
import subprocess
import os


if __name__ == '__main__':
	ANDROID_HOME = os.environ.get('ANDROID_HOME', None)

	if not ANDROID_HOME:
		raise RuntimeError('Please make sure, that the ANDROID_HOME environment variable is set correctly')

	subprocess.check_call([
		'python',
		'build_native.py'
	])

	subprocess.check_call([
		'ant',
		'-Dsdk.dir=%(ANDROID_HOME)s' % locals(),
		'-Dtarget=android-19',
		'debug'
	])

	#ant -Dsdk.dir=$ANDROID_HOME -Dtarget=android-16 debug

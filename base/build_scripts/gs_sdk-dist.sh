#!/bin/bash

echo "Compiling for OSX"
sh ./gs_osx_sdk-dist.sh || exit $?

echo "Compiling for iOS"
sh ./gs_ios_sdk-dist.sh || exit $?

echo "Compiling for Android"
sh ./gs_android_sdk-dist.sh || exit $?

echo "Packaging SDKs"
python gs_create_dist_packages.py || exit $?

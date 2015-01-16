#!/bin/bash

# this is here, so that you can override the output directory via environment variables, e.g. OUTPUT_DIRECTORY=../i_want_my_build_here sh gs_osx_sdk-dist.sh 
: ${OUTPUT_DIRECTORY:=../build}

MY_DIR=$(pushd $(dirname $BASH_SOURCE[0]) > /dev/null && pwd -P && popd > /dev/null)
CMAKE_SRC_DIR="$MY_DIR/../build_scripts"

mkdir -p "$OUTPUT_DIRECTORY" || exit $?

pushd "$OUTPUT_DIRECTORY"
	mkdir -p OSX_stl || exit $?
	mkdir -p OSX_eastl || exit $?
	mkdir -p xcode/OSX_stl || exit $?
	mkdir -p xcode/OSX_eastl || exit $?

	pushd xcode/OSX_stl
		cmake "$CMAKE_SRC_DIR" -GXcode  || exit $?
		xcodebuild -project Gamesparks.xcodeproj -target Gamesparks -configuration RelWithDebInfo || exit $?
		xcodebuild -project Gamesparks.xcodeproj -target sample02_connect_static -configuration RelWithDebInfo || exit $?
	popd

	cp -R xcode/OSX_stl/RelWithDebInfo/libGamesparks.a OSX_stl || exit $?
	
	pushd xcode/OSX_eastl
		cmake "$CMAKE_SRC_DIR" -DUSE_EASTL=1 -DNO_STL_FUNCTIONAL=1 -GXcode  || exit $?
		xcodebuild -project Gamesparks.xcodeproj -target Gamesparks -configuration RelWithDebInfo || exit $?
		xcodebuild -project Gamesparks.xcodeproj -target sample02_connect_static -configuration RelWithDebInfo || exit $?
	popd

	cp -R xcode/OSX_eastl/RelWithDebInfo/libGamesparks.a OSX_eastl || exit $?
popd

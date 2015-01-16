#!/bin/bash

# this is here, so that you can override the output directory via environment variables, e.g. OUTPUT_DIRECTORY=../i_want_my_build_here sh gs_ios_sdk-dist.sh 
: ${OUTPUT_DIRECTORY:=../build}

MY_DIR=$(pushd $(dirname $BASH_SOURCE[0]) > /dev/null && pwd -P && popd > /dev/null)
CMAKE_SRC_DIR="$MY_DIR/../build_scripts"

mkdir -p "$OUTPUT_DIRECTORY" || exit $?

pushd "$OUTPUT_DIRECTORY"
	mkdir -p xcode/iOS_stl || exit $?
	mkdir -p xcode/iOS_eastl || exit $?
	mkdir -p xcode/iOSSim || exit $?

	pushd xcode/iOS_eastl
		cmake $CMAKE_SRC_DIR -DUSE_EASTL=1 -DNO_STL_FUNCTIONAL=1 -DBUILD_IOS=1 -GXcode || exit $?
		xcodebuild -project Gamesparks.xcodeproj -target Gamesparks -configuration RelWithDebInfo -sdk iphoneos || exit $?
	popd

	pushd xcode/iOS_stl
		cmake $CMAKE_SRC_DIR -DBUILD_IOS=1 -GXcode || exit $?
		xcodebuild -project Gamesparks.xcodeproj -target Gamesparks -configuration RelWithDebInfo -sdk iphoneos || exit $?
	popd

	#pushd xcode/iOSSim
	#	cmake $CMAKE_SRC_DIR -DBUILD_IOS=1 -GXcode || exit $?
	#	xcodebuild -project Gamesparks.xcodeproj -target Gamesparks -configuration Release -sdk=iphonesimulator  || exit $?
	#popd

	mkdir -p iOS_eastl || exit $?
	mkdir -p iOS_stl || exit $?
	#lipo -create xcode/iOS/Release-iphoneos/libGamesparks.a xcode/iOSSim/Release-iphoneos/libGamesparks.a -o iOS/libGamesparks.a || exit $?

	# I temporary removed ios simulator build, because it is not working at the moment
	cp xcode/iOS_eastl/RelWithDebInfo-iphoneos/libGamesparks.a iOS_eastl/libGamesparks.a || exit $?
	cp xcode/iOS_stl/RelWithDebInfo-iphoneos/libGamesparks.a iOS_stl/libGamesparks.a || exit $?
popd

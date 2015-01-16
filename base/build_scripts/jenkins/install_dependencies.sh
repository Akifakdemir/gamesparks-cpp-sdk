#!/bin/bash

# change directory to the directory, where this script is in
pushd "$(dirname "$0")"

. config.sh

CMAKE_URL="http://www.cmake.org/files/v3.0/cmake-3.0.2-Darwin64-universal.tar.gz"
NDK_URL="http://dl.google.com/android/ndk/android-ndk-r10c-darwin-x86_64.bin"

if [ ! -f "$CMAKE_ROOT/bin/cmake" ]; then
	echo "installing missing dependency: cmake"
	
	mkdir -p "$CMAKE_ROOT"

	if [ ! -f "cmake.tar.gz" ]; then
		curl -L -o 'cmake.tar.gz' -C - "$CMAKE_URL" || exit 1
	fi

	tar -xvf cmake.tar.gz || exit 1
	mv cmake-3.0.2-Darwin64-universal/CMake.app/Contents/* "$CMAKE_ROOT" || exit 1

	rm -Rfv cmake-3.0.2-Darwin64-universal || exit 1
	rm -f cmake.tar.gz
fi

if [ ! -f "$NDK_ROOT/ndk-build" ]; then
	echo "installing missing dependency: ndk"

	mkdir -p "$NDK_ROOT"

	if [ ! -f "android-ndk.bin" ]; then
		curl -L -o 'android-ndk.bin' -C - "$NDK_URL" || exit 1
	fi

	chmod +x ./android-ndk.bin
	./android-ndk.bin x -o"$NDK_ROOT" -y || exit 1
	mv "$NDK_ROOT/android-ndk-r10c/"* "$NDK_ROOT" || exit 1
	rmdir "$NDK_ROOT/android-ndk-r10c" || exit 1
fi

rm -f android-ndk.bin cmake.tar.gz

popd

exit 0

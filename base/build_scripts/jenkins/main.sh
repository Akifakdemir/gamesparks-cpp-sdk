#!/bin/bash

# change directory to the directory, where this script is in
pushd "$(dirname "$0")"

	source config.sh

	#comment in for non-incremental builds
	#OUTPUT_DIRECTORY="$BUILD_DIR" PACKAGING_OUTPUT_DIRECTORY="$PACKAGING_OUTPUT_DIRECTORY" bash ../clean.sh || exit $?

	./install_dependencies.sh || exit 1

	echo "$BUILD_DIR"
	mkdir -p "$BUILD_DIR" || $?
	pushd .. || $?
		mkdir -p "$BUILD_DIR" || $?
		mkdir -p "$PACKAGING_OUTPUT_DIRECTORY" || $?

		PATH=$PATH:$NDK_ROOT:$CMAKE_ROOT/bin OUTPUT_DIRECTORY="$BUILD_DIR" \
			PACKAGING_OUTPUT_DIRECTORY="$PACKAGING_OUTPUT_DIRECTORY" \
			bash ./gs_sdk-dist.sh || exit $?
	popd
popd

exit 0

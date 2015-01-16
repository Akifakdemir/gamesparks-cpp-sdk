#!/bin/bash

# this is here, so that you can override the output directory via environment variables, e.g. OUTPUT_DIRECTORY=../i_want_my_build_here sh gs_android_sdk-dist.sh 
: ${OUTPUT_DIRECTORY:=../build}

mkdir -p $OUTPUT_DIRECTORY/Android || exit $?
ndk-build --directory=./jni || exit $?

for arch in armeabi armeabi-v7a x86; do
	mkdir -p "$OUTPUT_DIRECTORY/Android/$arch" || exit $?
	cp "./obj/local/$arch/libGamesparks.a" "$OUTPUT_DIRECTORY/Android/$arch/libGamesparks.a" || exit $?
done

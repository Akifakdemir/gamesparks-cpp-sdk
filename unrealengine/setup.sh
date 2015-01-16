#!/bin/sh

pushd ../base/build_scripts
sh gs_ios_sdk-dist.sh
sh gs_osx_sdk-dist.sh
popd

python setup_plugin.py
python setup_sample.py

echo Try to generate XCode project for the GameSparksSample
UE_VERSION="4.6"
MY_DIR=$(pushd $(dirname $BASH_SOURCE[0]) > /dev/null && pwd -P && popd > /dev/null) 
pushd "/Users/Shared/UnrealEngine/$UE_VERSION/Engine/Build/BatchFiles/Mac/"
./RocketGenerateProjectFiles.sh  -project="$MY_DIR/GameSparksSample/GameSparksSample.uproject"
./RocketGenerateProjectFiles.sh -project="$MY_DIR/GameSparksSample/GameSparksSample.uproject" -platforms=IOS -game 

popd
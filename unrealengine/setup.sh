#!/bin/sh

python setup_plugin.py
python setup_sample.py

echo Try to generate XCode project for the GameSparksSample
UE_VERSION="4.7"
MY_DIR=$(pushd $(dirname $BASH_SOURCE[0]) > /dev/null && pwd -P && popd > /dev/null) 
pushd "/Users/Shared/UnrealEngine/$UE_VERSION/Engine/Build/BatchFiles/Mac/"
./RocketGenerateProjectFiles.sh  -project="$MY_DIR/GameSparksSample/GameSparksSample.uproject"
./RocketGenerateProjectFiles.sh -project="$MY_DIR/GameSparksSample/GameSparksSample.uproject" -platforms=IOS -game 

popd
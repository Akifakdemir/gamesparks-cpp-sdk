# GameSparks Unreal Engine Plugin

This is a *early beta* of the Unreal Engine Plugin. Consider it as preview and except more features in future releases. 

# Features

* Base module to establish a connection to the GameSparks Service
* A simple GSActor implementation as sample to use the Plugin from C++ Code
* A first implementation for Blueprint support 

To get everything working out of the box, just follow the steps

# Prerequisites (Depending on platforms you want to support)
1. Unreal Engine 4.6
2. [Android NDK](https://developer.android.com/tools/sdk/ndk/index.html#download)
3. [XCode](https://developer.apple.com/xcode/downloads/)
4. [Visual Studio](http://www.visualstudio.com/downloads/download-visual-studio-vs.aspx)
5. [CMake](http://www.cmake.org/download/) or ```brew install cmake``` on OSX
6. [python 2.x](https://www.python.org/downloads/) (already installed on OSX)

# Windows 

0. make sure you get the base sdk automated build working (see README.MD in "base")
1. run "setup.bat" (This will build android, win32 and win64)
2. create the visual studio solution of the sample and run it

# OSX

0. make sure you get the base sdk automated build working (see README.MD in "base")
1. run "the setup.sh" from the Terminal (This will build the baseSDK for OSX and iOS)

We setup up a automated XCode project generation for the sample project. This is setup to the 4.6 Version. You can manually change it by editing the "setup.sh" file and change the UE_VERSION version variable.

Known issue: The OSX Version is currently using EASTL as STL-Port for std::string and std::vector. Cause of this issue is a bug, where the build pipeline for iOS is not linking against the STL when compiling code as plugin. We're working to solve this issue in future releases.

# Get the sample running

You need to setup your API keys to get the sample running. We implemented two ways establishing the connection.

1. plugin\GameSparks\Source\GameSparks\Private\GSActor.cpp - You can setup your credentials in code there. 
2. Within the Editor, open up the Blueprint folder and edit the CustomGameMode-Blueprint. You will see the GameSparks-Connect node, where you can setup your API and Secret.


## Optional

If you want to get changes from the plugin back, just call "copy_changes.bat". This will copy all the changes from the sample folder into the plugin folder

# Platform Support Status

|                        | *Compiles* | *Packaging* | *Tests* |
|------------------------|------------|-------------|---------|
| *iOS armv7*            |    YES     |     PASS    |   NONE  |
| *iOS armv7s*           |    YES     |     PASS    |   NONE  |
| *iOS arm64*            |    YES     |     PASS    |   NONE  |
| *iOS Simulator*        |    NO      |     NONE    |   NONE  |
| *Android armeabi*      |    YES     |     PASS    |   NONE  |
| *Android armeabi-v7a*  |    YES     |     PASS    |   NONE  |
| *Android x86*          |    YES     |     PASS    |   NONE  |
| *OSX x64*              |    YES     |     PASS    |   NONE  |
| *Win32*                |    YES     |     PASS    |   NONE  |
| *Win64*                |    YES     |     PASS    |   NONE  |

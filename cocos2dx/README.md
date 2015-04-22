# using the GameSparks C++ SDK with Cocos2D-x

## Directory Layout
* Sample - the sample for Cocos2D-x 3

## Building

### Prerequisites
1. [python 2.x](https://www.python.org/downloads/) (already installed on OSX)
2. [XCode](https://developer.apple.com/xcode/downloads/)
3. [Visual Studio](http://www.visualstudio.com/downloads/download-visual-studio-vs.aspx)

### Automated (on OSX)

To perform the steps below in an automated manner, execute build_sample.py
It might be neccessary to execute Sample/cocos2d/setup.py to complete the cocs setup

### Build C++ SDK

Windows: ```python ../base/build_script/jenkins/main.py```
OSX: ```bash ../base/build_script/jenkins/main.sh```

This will download the dependencies (cmake & android NDK) and build the SDK for all platforms
that can be build on your machine.

### setup cocos2d

- [Download Cocos2dx v3.x](http://www.cocos2d-x.org/download)
- extract the archive
- copy the extracted folder into this directory and rename it to cocos2d
- execute ~/SDKs/cocos2d-x-3.4/setup.py and follow the instructionns
- If you want to build the samples for android, you have to have java, android ndk and android sdk installed.

### Set your credentials

open Sample/Classes/AppDelegate.cpp and serch for "GS.Initialise" (somewhere around line 98). insert your authkey and secret.

### Build and Run the Sample

The directory Sample contains several project directories (proj.*). Open the
project for a platform of your choice and compile it.

You can also use cmake to create the project files

To get acquainted with what's necessary to integrate GameSparks into a Cocos2d-X project,
search for "*GS*" (without the quotes). All parts of the code that have to do with GameSparks
are marked this way.

#### windows

open Sample/win32.proj/CocosSample.sln

or

```
cd Sample
cocos run -p windows
```

#### android

```
cd Sample
cocos run -p android
```

# GameSparks Cocos2D-x Samples

## Directory Layout
* Sample - the sample for Cocos2D-x 3

## Building

### Prerequisites
1. [python 2.x](https://www.python.org/downloads/) (already installed on OSX)
2. [XCode](https://developer.apple.com/xcode/downloads/)
3. [Visual Studio](http://www.visualstudio.com/downloads/download-visual-studio-vs.aspx)

### Build C++ SDK

Windows: ```python ../base/build_script/jenkins/main.py```
OSX: ```bash ../base/build_script/jenkins/main.sh```

This will download the dependencies (cmake & android NDK) and build the SDK for all platforms
that can be build on your machine.

### setup cocos2d

run Sample/cocos2d/setup.py and follow the instructions.
If you want to build the samples for android, you have to have java, android ndk and android sdk installed.

### Set your credentials

open Sample/Classes/AppDelegate.cpp and serch for "GS.Initialise" (somewhere around line 98). insert your authkey and secret.

### Build and Run the Sample

The directory Sample contains several project directories (proj.*). Open the
project for a platform of your choice and compile it.

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

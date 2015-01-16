# GameSparks SDK Sources

## Directory Layout
* build_scripts - scripts to perform the builds for various platforms
* gs_src_public - the public part of the SDK
* gs_src_private - the internal part of the SDK
* licenses - 3rd party library licenses
* build - all output of the build-scripts goes here
* dist - SDK distribution packages will end up here

Note: the build and dist are git-ignored.

## Building

### Prerequisites
1. [Android NDK](https://developer.android.com/tools/sdk/ndk/index.html#download)
2. [XCode](https://developer.apple.com/xcode/downloads/)
3. [Visual Studio](http://www.visualstudio.com/downloads/download-visual-studio-vs.aspx)
4. [CMake](http://www.cmake.org/download/) or ```brew install cmake``` on OSX
5. [python 2.x](https://www.python.org/downloads/) (already installed on OSX)

### Build all Automated

1. ``` call build_script/jenkins/main.py```

It will build Android and Win32 and Win64 on Windows.

### iOS
#### prerequisites: XCode

1. ```gs_ios_sdk-dist.sh```


### OSX
#### prerequisites: XCode

1. run ```gs_osx_sdk-dist.sh```


### Android (on OSX)
#### prerequisites: Android NDK

1. optional: edit jni/Application.mk to match your build configuration (ABI, etc. )
2. run: ```PATH=$PATH:<path-to-ndk> bash gs_android_sdk-dist.sh```


### Building & Packaging on OSX:
#### prerequisites: Android NDK, XCode, CMake

1. run ```PATH=$PATH:<path-to-ndk> bash gs_sdk-dist.sh```


### Android (on Windows)
#### prerequisites: Android NDK

1. optional: edit jni/Application.mk to match your build configuration (ABI, etc. )
2. run:
```
set PATH=%PATH%;<path-to-ndk>
gs_android_sdk-dist.bat
```


### Win32 / Win64
#### prerequisites: Visual Studio 2012+

1. run for 32/64 bit:
```
set PATH=%PATH%;<path-to-cmake-bin>
gs_win_sdk-dist.bat
```

2. run for 32 bit:
```
set PATH=%PATH%;<path-to-cmake-bin>
gs_win32_sdk-dist.bat
```

3. run for 64 bit:
```
set PATH=%PATH%;<path-to-cmake-bin>
gs_win64_sdk-dist.bat
```

### Building & Packaging on Windows:
#### prerequisites: Android NDK, Visual Studio 2012+, CMake, Python

1. run:
```
set PATH=%PATH%;<path-to-cmake-bin>
set PATH=%PATH%;<path-to-ndk>
gs_sdk-dist.bat
```

## Modifying the code

By default, the buildscripts remove the generated project files and intermediate build output.
If you want to keep the generated project files, just comment out the last line(s) in the build
script for the platform you're interested in.

# Platform Support Status

|                        | *Compiles* | *Packaging* | *Tests* |
|------------------------|------------|-------------|---------|
| *iOS armv7*            |    YES     |     PASS    |   NONE  |
| *iOS armv7s*           |    YES     |     PASS    |   NONE  |
| *iOS arm64*            |    YES     |     PASS    |   NONE  |
| *iOS Simulator*        |    YES     |     PASS    |   NONE  |
| *Android armeabi*      |    YES     |     PASS    |   NONE  |
| *Android armeabi-v7a*  |    YES     |     PASS    |   NONE  |
| *Android x86*          |    YES     |     PASS    |   NONE  |
| *OSX x64*              |    YES     |     PASS    |   NONE  |
| *Win32*                |    YES     |     PASS    |   NONE  |
| *Win64*                |    YES     |     PASS    |   NONE  |

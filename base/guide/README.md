# Quick Start Guide for the base SDK {#QuickStartGuideForTheBaseSDK}

## Prerequisites

### OS X

1. [XCode](https://developer.apple.com/xcode/downloads/)


### Windows

1. [Visual Studio](http://www.visualstudio.com/downloads/download-visual-studio-vs.aspx)
2. [python 2.x](https://www.python.org/downloads/)


## Compile the SDK

The build-scripts download the required dependencies and compile all libraries that can be build on the host platform.

### OS X

1. Open a Terminal (Press cmd+space, enter "Terminal" and press enter)
2. cd into the gamesparks SDK directory
3. run the build script

	./base/build_scripts/jenkins/main.sh

4. The zipped SDKs can be found in base/dist/

### Windows

1. open a command prompt (win+r, enter cmd, press enter)
2. cd into the gamesparks sdk directory

	cd c:\path\to\gamesparks\sdk

3. run the build script

	.\base\build_scripts\jenkins\main.py

4. The zipped SDKs can be found in base/dist/


## Compile and run the sample

### OS X

1. open base/build/xcode/OSX_stl/Gamesparks.xcodeproj
2. insert your API credentials retrieved from [The GameSparks Portal](http://portal.gamesparks.net/) into sample_configuration.cpp

		NativePlatformDescription()
		:IGSPlatform
		(
			"<GameSparks Api Key>", // insert your auth key
			"<GameSparks Api Secret>", // insert your secret
			true, // use the preview server?
			true // do you want verbose debugging?
		)

3. select sample01_connect/My Mac (64 bit) from the scheme dropdown menu
4. press cmd+r to compile and run the sample

### Windows

1. open the Visual Studio Solution located at base\build\visual_studio_project_files_<platform>_<visual studio version>\Gamesparks.sln
2. insert your API credentials retrieved from [The GameSparks Portal](http://portal.gamesparks.net/) into sample_configuration.cpp

		NativePlatformDescription()
		:IGSPlatform
		(
			"<GameSparks Api Key>", // insert your auth key
			"<GameSparks Api Secret>", // insert your secret
			true, // use the preview server?
			true // do you want verbose debugging?
		)

3. right click in sample01_connect in the solution explorer and select "Set as StartUp Project"
4. press F5



## Using the SDK without pre-compiling the libraries
	
	Note: This is advanced usage of the SDK.

If you prefer to not use precompiled librarties, there's an alternative way to include the SDK into your project.
To do that, you have to add a couple of source files to your project and add some include paths:

1. add base/dependencies/cjson|easywsclient|google|hmac|/*.cpp/*.c to your project
2. add base/src/*.cpp to your project
3. add base/include to your header search path
4. make sure, that your projects against libopenssl
5. set the preprocessor definition SSL_SUPPORT to 1


## Next Steps

explore the [API docs](./annotated.html) and the [Examples](./examples.html) of the base SDK.

set OUTPUT_DIRECTORY=../build

@rem cleanup
rmdir /s /q obj
rmdir /s /q %OUTPUT_DIRECTORY%/Android
mkdir "%OUTPUT_DIRECTORY%/Android"
mkdir "%OUTPUT_DIRECTORY%/Android/armeabi"
mkdir "%OUTPUT_DIRECTORY%/Android/armeabi-v7a"
mkdir "%OUTPUT_DIRECTORY%/Android/x86"

set NDK_PROJECT_PATH=../
call ndk-build --directory=./jni

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 64
	exit /b 1
)

xcopy ".\obj\local\armeabi\libGamesparks.a" "%OUTPUT_DIRECTORY%/Android/armeabi" /Y
xcopy ".\obj\local\armeabi-v7a\libGamesparks.a" "%OUTPUT_DIRECTORY%/Android/armeabi-v7a"/Y
xcopy ".\obj\local\x86\libGamesparks.a" "%OUTPUT_DIRECTORY%/Android/x86" /Y

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 64
	exit /b 1
)

@rem rmdir /s /q obj

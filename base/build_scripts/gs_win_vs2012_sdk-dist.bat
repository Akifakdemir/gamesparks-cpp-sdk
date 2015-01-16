call gs_win32_vs2012_sdk-dist.bat

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 32
	exit /b 1
)

call gs_win64_vs2012_sdk-dist.bat

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 64
	exit /b 1
)

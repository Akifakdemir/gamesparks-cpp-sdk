echo =========================== Compiling Win32 ===========================
gs_win-dist.py

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 64
	exit /b 1
)

echo =========================== Compiling Android ===========================
call gs_android_sdk-dist.bat

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 64
	exit /b 1
)

echo =========================== Packaging SDKs ===========================
gs_create_dist_packages.py

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build for win 64
	exit /b 1
)

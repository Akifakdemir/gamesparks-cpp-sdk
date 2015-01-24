@echo off

call python gs_win-buildtests.py

if %ERRORLEVEL% NEQ 0 (
	echo Failed to build tests for win 32 and/or win 64
	exit /b 1
)

call python gs_win-runtests.py

if %ERRORLEVEL% NEQ 0 (
	echo Failed to run tests for win 32 and/or win 64
	exit /b 1
)
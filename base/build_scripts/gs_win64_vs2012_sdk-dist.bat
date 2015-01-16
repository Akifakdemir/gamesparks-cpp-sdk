@rem be aware, that forward slashes sometimes work and sometime they don't
set OUTPUT_DIRECTORY=..\build

@rem figure out, where msbuild.exe is located
@rem prior to windows 7, we have to use skip=4
FOR /F "usebackq skip=2 tokens=3" %%A IN (`REG QUERY "HKLM\SOFTWARE\Microsoft\MSBuild\ToolsVersions\4.0" /v MSBuildToolsPath 2^>nul`) DO (
    @set MSBUILD_DIR=%%A
    @set MSBUILD="%%AMSBuild.exe"
)

if defined MSBUILD_DIR (
	echo "Path to MSBuild is %MSBUILD%"
) else (
	echo "failed to find location of MSBuild.exe. Is Visual Studio Installed?"
	exit /B 1
)

@rem for win64
@rem rd "%OUTPUT_DIRECTORY%/visual_studio_project_files_win64" /S /Q
mkdir "%OUTPUT_DIRECTORY%/visual_studio_project_files_win64"
mkdir "%OUTPUT_DIRECTORY%/win64"

pushd "%OUTPUT_DIRECTORY%/visual_studio_project_files_win64"
cmake ../../build_scripts -G "Visual Studio 11 Win64"
%MSBUILD% Gamesparks.sln /property:Configuration=Debug /target:Gamesparks
%MSBUILD% Gamesparks.sln /property:Configuration=Release /target:Gamesparks
popd

@rem copy build results
copy "%OUTPUT_DIRECTORY%\visual_studio_project_files_win64\Debug\Gamesparks.lib" "%OUTPUT_DIRECTORY%\win64\Gamesparks_d.lib"
copy "%OUTPUT_DIRECTORY%\visual_studio_project_files_win64\Release\Gamesparks.lib" "%OUTPUT_DIRECTORY%\win64\Gamesparks.lib"

@rem comment out the next line, if you want to keep the project files
@rem rd "%OUTPUT_DIRECTORY%\visual_studio_project_files_64" /S /Q

// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class GameSparks : ModuleRules
{
	public GameSparks(TargetInfo Target)
	{
        //Definitions.Add("GS_USE_EASTL=1");

		//Private Paths
        PrivateIncludePaths.AddRange(new string[] { 
			"GameSparks/Private"
		});

        PublicDependencyModuleNames.AddRange(
			new string[] { 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore",
				"RHI",
                "OnlineSubsystemUtils"
			}
		);

        AddGameSparksSDK(Target);
       
        PrivateDependencyModuleNames.Add("GameSparks");

        DynamicallyLoadedModuleNames.Add("Json");
        PublicIncludePathModuleNames.Add("Json");
        //DynamicallyLoadedModuleNames.Add("Settings");
        //PublicIncludePathModuleNames.Add("Settings");
	}

    private string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

    private string GameSparksPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "..", "GameSparksBaseSDK")); }
    }

    private void AddGameSparksSDK(TargetInfo Target)
    {
        AddGameSparksIncludePath();

        switch (Target.Platform)
        {
            case UnrealTargetPlatform.Win64:
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "GameSparks", "libVSWin64", "GameSparks.lib"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libVSWin64", "libeay32.lib"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libVSWin64", "ssleay32.lib"));
                break;
            case UnrealTargetPlatform.Win32:
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "GameSparks", "libVSWin32", "GameSparks.lib"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libVSWin32", "libeay32.lib"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libVSWin32", "ssleay32.lib"));
                break;
            case UnrealTargetPlatform.Android:
                PublicLibraryPaths.Add(Path.Combine(GameSparksPath, "libs", "GameSparks", "libAndroid_armeabi"));
                PublicLibraryPaths.Add(Path.Combine(GameSparksPath, "libs", "GameSparks", "libAndroid_armeabi-v7a"));
                PublicLibraryPaths.Add(Path.Combine(GameSparksPath, "libs", "GameSparks", "libAndroid_x86"));

                PublicAdditionalLibraries.Add(Path.Combine(GameSparksPath, "libs", "GameSparks", "libAndroid_armeabi", "libGamesparks.a"));
                PublicAdditionalLibraries.Add(Path.Combine(GameSparksPath, "libs", "GameSparks", "libAndroid_armeabi-v7a", "libGamesparks.a"));
                PublicAdditionalLibraries.Add(Path.Combine(GameSparksPath, "libs", "GameSparks", "libAndroid_x86", "libGamesparks.a"));
                break;
            case UnrealTargetPlatform.IOS:
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "GameSparks", "libIOS", "libGamesparks.a"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libIOS", "libcrypto.a"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libIOS", "libssl.a"));
                //AddPublicLibrary("c++");
                Definitions.Add("STL_FUNCTIONAL_SUPPORTED=0");
                Definitions.Add("GS_USE_EASTL=1");
                break;
            case UnrealTargetPlatform.Mac:
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "GameSparks", "libOSX", "libGamesparks.a"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libOSX", "libcrypto.a"));
                AddPublicLibrary(Path.Combine(GameSparksPath, "libs", "openssl", "libOSX", "libssl.a"));
                //Definitions.Add("STL_FUNCTIONAL_SUPPORTED=0");
                //Definitions.Add("GS_USE_EASTL=1");
                break;
            case UnrealTargetPlatform.XboxOne:
            case UnrealTargetPlatform.PS4:
            case UnrealTargetPlatform.WinRT:
            case UnrealTargetPlatform.WinRT_ARM:
            case UnrealTargetPlatform.HTML5:
            case UnrealTargetPlatform.Linux:
            default:
                throw new NotImplementedException("This target platform is not configured for GameSparks SDK: " + Target.Platform.ToString());
        }

    }

    private void AddGameSparksIncludePath()
    {
        AddPublicIncludePath(Path.Combine(GameSparksPath, "include"));
        AddPublicIncludePath(Path.Combine(GameSparksPath, "include", "eastl", "include"));
    }

    private void AddPublicIncludePath(string path)
    {
        PublicIncludePaths.Add(path);
        Console.WriteLine("Adding \"" + path + "\" as public include path.");
    }

    private void AddPublicLibrary(string locationOfLibFile)
    {
        Console.WriteLine("Adding \"" + locationOfLibFile + "\" as additional library for linking.");
        PublicAdditionalLibraries.Add(locationOfLibFile);
    }
}

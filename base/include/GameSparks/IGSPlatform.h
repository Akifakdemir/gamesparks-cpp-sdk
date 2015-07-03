// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef IGSPlatform_h__
#define IGSPlatform_h__

#pragma once

#include "./gsstl.h"
#include <GameSparks/GSLeakDetector.h>
#include <GameSparks/GSPlatformDeduction.h>
#include "GSTime.h"
#include <cassert>

#if GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
#	include <sys/types.h>
#	include <unistd.h>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
#	include <shlwapi.h>
#	pragma comment(lib,"shlwapi.lib")
#	include "shlobj.h"
#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC
#   include "TargetConditionals.h"
#   include <sys/stat.h> // for mkdir

/* works like mkdir(1) used as "mkdir -p" */
static void mkdirp(const char *dir) {
    char tmp[PATH_MAX];
    char *p = NULL;
    size_t len;
    
    snprintf(tmp, sizeof(tmp),"%s",dir);
    len = strlen(tmp);
    if(tmp[len - 1] == '/')
        tmp[len - 1] = 0;
    for(p = tmp + 1; *p; p++)
        if(*p == '/') {
            *p = 0;
            mkdir(tmp, S_IRWXU | S_IRWXG);
            *p = '/';
        }
    mkdir(tmp, S_IRWXU | S_IRWXG);
}
#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    gsstl::string gs_ios_get_writeable_base_path();
#endif


namespace GameSparks
{
	namespace Core
	{
		//! This class is passed to the constructor of the GS_ class.
		//! If you want to customize platofrm related behaviour of the SDK you can inherit from
		//! this class. There already are specialisations for Cocos2dx, Marmalade and Unreal.
		class IGSPlatform
		{
			public:
				/*! Construct a IGSPlatform.
				 * @param apiKey the "GameSparks Api Key" of your project received from https://portal.gamesparks.net/
				 * @param apiKey the "GameSparks Api Secret" of your project received from https://portal.gamesparks.net/
				 * @param usePreviewServer pass true if you want to use the preview server. Use false for the production server
				 * @param verboseLogging more verbose logging. Usefull for debugging
				 */
				IGSPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool usePreviewServer, bool verboseLogging=false)
					: m_apiKey(apikey)
					, m_secret(secret)
					, m_verboseLogging(verboseLogging)
				{
					SetPreviewMode(usePreviewServer);

					m_AuthToken = "";
					m_RequestTimeoutSeconds = 5.0f;
				}

				//! Gets a unique identifier for the device
				virtual gsstl::string GetDeviceId() const = 0;

				//! IOS or AND or WP8 - Required for in app purchases
				virtual gsstl::string GetDeviceOS() const
				{
					#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
						return "OSX";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
						return "IOS";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
						return "Android";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
						return "W8";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_LINUX
						return "Linux";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE
						return "Marmelade";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_BADA
						return "Bada";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_BLACKBERRY
						return "Blackberry";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_NACL
						return "NaCl";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_EMSCRIPTEN
						return "emscripten";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_TIZEN
						return "Tizen";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_QT5
						return "QTS";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_WINRT
						return "W8";
					#elif GS_TARGET_PLATFORM == GS_PLATFORM_WP8
						return "WP8";
					#else
					#   error "Unsupported platform"
						return "Unknown";
					#endif
				}

				//! Will be used in analytics reports
				virtual gsstl::string GetPlatform() const
				{
					return GetDeviceOS();
				}

				//! Will be used in analytics reports
				virtual gsstl::string GetSDK() const = 0;

				//! Will be used in analytics reports
				virtual gsstl::string GetDeviceType() const = 0;

				//! Set to true to get extended debugging information
				virtual bool GetExtraDebug() const
				{
					return m_verboseLogging;
				}

				//! return the API secret. The default returns the value passed into the constructor
				virtual gsstl::string GetGameSparksSecret() const
				{
					return m_secret;
				}

				//! return the preview service url. You probably don't want to customize this
				virtual gsstl::string GetPreviewServiceUrl() const
				{
					return "wss://preview.gamesparks.net/ws/" + m_apiKey;
				}

				//! return the live service url. You probably don't want to customize this
				virtual gsstl::string GetLiveServiceUrl() const
				{
					return "wss://service.gamesparks.net/ws/" + m_apiKey;
				}

				//! Service url from the portal
				virtual gsstl::string GetServiceUrl() { return GetPreviewMode() ? GetPreviewServiceUrl() : GetLiveServiceUrl(); }

				/// returns the Auth token
				virtual gsstl::string GetAuthToken() const { return m_AuthToken; }

				/// sets the auth token
                virtual void SetAuthToken(const gsstl::string& authToken)
                {
                    m_AuthToken = authToken;
                    StoreValue("gamesparks.authtoken", authToken);
                }

				/// returns the player id of the currently authenticated user
				virtual gsstl::string GetUserId() const { return m_UserId; }

				/// sets the player id for the currently authenticated user
                virtual void SetUserId( const gsstl::string& userId)
                {
                    m_UserId = userId;
                    StoreValue("gamesparks.userid", userId);
                }

				//! Receives debugging information from the API
				//! If you need more sophisticated logging, this is the method you should override
				virtual void DebugMsg(const gsstl::string& message) const = 0;

				/// returns the request timeout in seconds.
				virtual Seconds GetRequestTimeoutSeconds() const { return m_RequestTimeoutSeconds; }

				/// sets the request timeout in seconds
				virtual void SetRequestTimeoutSeconds(Seconds requestTimeoutSeconds) { m_RequestTimeoutSeconds = requestTimeoutSeconds; }

				/// sets wether to use the preview or the live server.
				/// should be called before the GS-Service is initialized
				virtual void SetPreviewMode(bool previewModeActive) { m_PreviewMode = previewModeActive; }

				/// return true, if the preview server is used; false if the production server is used.
				virtual bool GetPreviewMode() const { return m_PreviewMode; }

				//void ExecuteOnMainThread(Action action);

                //! store *value* at *key*.
				void StoreValue(const gsstl::string& key, const gsstl::string& value)
				{
					// TODO: port to all the platforms
					FILE* f = fopen(ToWritableLocation(key).c_str(), "wb");
					assert(f);
					if (!f)
					{
                    	DebugMsg("**** Failed to store value to '" + ToWritableLocation(key) + "'");
                    	return;
					}
					size_t written = fwrite(value.c_str(), 1, value.size(), f);
					assert(written == value.size());
					fclose(f);
				}

                //! Load Value associated with *key*. returns empty string, if key could not be retrieved.
				gsstl::string LoadValue(const gsstl::string& key)
				{
					// TODO: port to all the platforms
					FILE *f = fopen(ToWritableLocation(key).c_str(), "rb");
					
                    if(!f)
                    {
                    	//DebugMsg("**** Failed to load value from '" + ToWritableLocation(key) + "'");
                        return "";
                    }
                    
					fseek(f, 0, SEEK_END);
					long fsize = ftell(f);
					if (fsize == 0)
					{
						fclose(f);
						return "";
					}
					fseek(f, 0, SEEK_SET);
					gsstl::vector<char> bytes(fsize);
					size_t read_bytes = fread(&bytes.front(), 1, fsize, f);
					assert(read_bytes == fsize);
					fclose(f);
					return gsstl::string( bytes.begin(), bytes.end() );
				}

				// TODO: port to all the platforms
				virtual gsstl::string ToWritableLocation(gsstl::string desired_name)
				{
					desired_name = "gamesparks_" + desired_name;

					#if GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE || defined(GS_OVERRIDE_TOWRITABLELOCATION) // marmalade || windows; Note, that windows is for testing only. You should not put the files into the working directoy
                    // http://docs.madewithmarmalade.com/display/MD/S3E+File+overview
					// This should work on marmalade
					return desired_name;

					#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32

					static gsstl::string base_path;

					if (base_path.empty())
					{
						TCHAR szPath[MAX_PATH];
						if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szPath)))
						{
							base_path = szPath;
						}
						else
						{
							DebugMsg("Failed to get CSIDL_APPDATA path.");
							base_path = "./";
							assert(false);
						}

						base_path += "\\GameSparks\\" + m_apiKey + "\\";

						int result = SHCreateDirectoryEx(NULL, base_path.c_str(), NULL);

						if (
							result != ERROR_SUCCESS &&
							result != ERROR_FILE_EXISTS &&
							result != ERROR_ALREADY_EXISTS
						)
						{
							DebugMsg("Failed to create directory.");
							assert(false);
						}
					}

					assert(!base_path.empty());

					return base_path + desired_name;

					#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
                    
                    //////////////////////////////// Android
					// http://stackoverflow.com/questions/6276933/getfilesdir-from-ndk
					char buf[200]; // 64bit int can be 20 digits at most
					sprintf(buf,"/proc/%i/cmdline", (int)getpid());

					FILE* f = fopen(buf, "rb");
					if (!f)
					{
						DebugMsg("Failed to get writable path");
						return desired_name;
					}
					fread(buf, 1, sizeof(buf), f);
					fclose(f);
					// bytes not contains the list of null separated command line arguments, the string constructor below will copy until the first null byte
					return "/data/data/" + gsstl::string(buf) + "/" + desired_name;

					#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC

                    ////////////////// OS X
                    static gsstl::string base_path;
                    if (base_path.empty())
                    {
                        char* homedir = getenv("HOME");
                        assert(homedir);
                        
                        gsstl::string writable_path(homedir);
                        
                        writable_path += "/Library/Application Support/GameSparks/" + m_apiKey + "/";
                        
                        struct stat s = {0};
                        
                        if (0 != stat(writable_path.c_str(), &s) ) // Check if directory exists
                        {
                            mkdirp(writable_path.c_str());
                        }
                    
                        base_path = writable_path;
                    }
                    
                    return base_path + desired_name;
                    
                    #elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
                    static gsstl::string base_path = gs_ios_get_writeable_base_path();
                    return base_path + "/" + desired_name;
					#else
                    #   error "ToWritableLocation not implemented for this platform. If you're planing on overriding it yourself, please define GS_OVERRIDE_TOWRITABLELOCATION"
					#endif
				}
			protected:
				gsstl::string m_AuthToken; ///< the stored auth token received from the server
				gsstl::string m_UserId; ///< id of currently authenticated user
				Seconds m_RequestTimeoutSeconds; ///< after how many seconds a request will time out
				bool m_PreviewMode; ///< preview or production server?

				gsstl::string m_apiKey; ///< the api key from https://portal.gamesparks.net/
				gsstl::string m_secret; ///< the secret from from https://portal.gamesparks.net/

				bool m_verboseLogging; ///< use verbose logging?
           	private:
           		friend class GS_;
           		void DurableInit()
           		{
                    m_AuthToken = LoadValue("gamesparks.authtoken");
                    m_UserId = LoadValue("gamesparks.userid");
           		}

	            GS_LEAK_DETECTOR(IGSPlatform);
		};
	}
}
#endif // IGSPlatform_h__
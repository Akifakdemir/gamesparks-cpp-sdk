// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef IGSPlatform_h__
#define IGSPlatform_h__

#pragma once

#include "./gsstl.h"
#include <GameSparks/GSLeakDetector.h>
#include <GameSparks/GSPlatformDeduction.h>
#include "GSTime.h"

namespace GameSparks
{
	namespace Core
	{
		class IGSPlatform
		{
		public:
			IGSPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool usePreviewServer, bool verboseLogging=false)
				: m_apiKey(apikey)
				, m_secret(secret)
				, m_verboseLogging(verboseLogging)
			{
				SetPreviewMode(usePreviewServer);

				m_AuthToken = "";
				m_RequestTimeoutSeconds = 5.0f;
				m_PreviewMode = true;
			}

			//Gets a unique identifier for the device
			virtual gsstl::string GetDeviceId() const = 0;

			//IOS or AND or WP8 - Required for in app purchases
			virtual gsstl::string GetDeviceOS() const
			{
				#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
					return "OSX";
				#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
					return "IOS";
				#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
					return "Android";
				#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
					return "Win32";
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
				#   error "Unsupported platform or not compiling for cocos"
					return "Unknown";
				#endif
			}

			//Will be used in analytics reports
			virtual gsstl::string GetPlatform() const
			{
				return GetDeviceOS();
			}

			//Will be used in analytics reports
			virtual gsstl::string GetSDK() const = 0;

			//Will be used in analytics reports
			virtual gsstl::string GetDeviceType() const = 0;

			//Set to true to get extended debugging information
			virtual bool GetExtraDebug() const
			{
				return m_verboseLogging;
			}

			virtual gsstl::string GetGameSparksSecret() const
			{
				return m_secret;
			}

			virtual gsstl::string GetPreviewServiceUrl() const
			{
				return "wss://preview.gamesparks.net/ws/" + m_apiKey;
			}

			virtual gsstl::string GetLiveServiceUrl() const
			{
				return "wss://service.gamesparks.net/ws/" + m_apiKey;
			}

			//Service url from the portal
			virtual gsstl::string GetServiceUrl() { return GetPreviewMode() ? GetPreviewServiceUrl() : GetLiveServiceUrl(); }

			virtual gsstl::string GetAuthToken() const { return m_AuthToken; }
			virtual void SetAuthToken(const gsstl::string& authToken) { m_AuthToken = authToken; }

			//Receives debugging information from the API
			virtual void DebugMsg(const gsstl::string& message) const = 0;

			virtual Seconds GetRequestTimeoutSeconds() const { return m_RequestTimeoutSeconds; }
			virtual void SetRequestTimeoutSeconds(Seconds requestTimeoutSeconds) { m_RequestTimeoutSeconds = requestTimeoutSeconds; }

			virtual void SetPreviewMode(bool previewModeActive) { m_PreviewMode = previewModeActive; }
			virtual bool GetPreviewMode() const { return m_PreviewMode; }

			//void ExecuteOnMainThread(Action action);
		protected:
			gsstl::string m_AuthToken;
			Seconds m_RequestTimeoutSeconds;
			bool m_PreviewMode;

			gsstl::string m_apiKey;
			gsstl::string m_secret;

			bool m_verboseLogging;
            
            GS_LEAK_DETECTOR(IGSPlatform);
		};
	}
}
#endif // IGSPlatform_h__
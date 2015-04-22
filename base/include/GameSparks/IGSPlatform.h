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
				virtual void SetAuthToken(const gsstl::string& authToken) { m_AuthToken = authToken; }

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
			protected:
				gsstl::string m_AuthToken; ///< the stored auth token received from the server
				Seconds m_RequestTimeoutSeconds; ///< after how many seconds a request will time out
				bool m_PreviewMode; ///< preview or production server?

				gsstl::string m_apiKey; ///< the api key from https://portal.gamesparks.net/
				gsstl::string m_secret; ///< the secret from from https://portal.gamesparks.net/

				bool m_verboseLogging; ///< use verbose logging?
           	private:
	            GS_LEAK_DETECTOR(IGSPlatform);
		};
	}
}
#endif // IGSPlatform_h__
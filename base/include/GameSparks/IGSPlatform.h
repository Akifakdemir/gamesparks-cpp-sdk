#pragma once

#include "./gsstl.h"

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
				m_RequestTimeoutSeconds = 5;
				m_PreviewMode = true;
			}

			//Gets a unique identifier for the device
			virtual gsstl::string GetDeviceId() const = 0;

			//IOS or AND or WP8 - Required for in app purchases
			virtual gsstl::string GetDeviceOS() const = 0;

			//Will be used in analytics reports
			virtual gsstl::string GetPlatform() const = 0;

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
				return "wss://preview.gamesparks.net/ws/" + m_apiKey;
			}

			//Service url from the portal
			virtual gsstl::string GetServiceUrl() { return GetPreviewMode() ? GetPreviewServiceUrl() : GetLiveServiceUrl(); }

			virtual gsstl::string GetAuthToken() const { return m_AuthToken; }
			virtual void SetAuthToken(const gsstl::string& authToken) { m_AuthToken = authToken; }

			//Receives debugging information from the API
			virtual void DebugMsg(const gsstl::string& message) const = 0;

			virtual int GetRequestTimeoutSeconds() const { return m_RequestTimeoutSeconds; }
			virtual void SetRequestTimeoutSeconds(int requestTimeoutSeconds) { m_RequestTimeoutSeconds = requestTimeoutSeconds; }

			virtual void SetPreviewMode(bool previewModeActive) { m_PreviewMode = previewModeActive; }
			virtual bool GetPreviewMode() const { return m_PreviewMode; }

			//void ExecuteOnMainThread(Action action);
		protected:
			gsstl::string m_AuthToken;
			int m_RequestTimeoutSeconds;
			bool m_PreviewMode;

			gsstl::string m_apiKey;
			gsstl::string m_secret;

			bool m_verboseLogging;
		};
	}
}
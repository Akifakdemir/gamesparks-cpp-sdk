#pragma once

#include "./IGSPlatform.h"

namespace GameSparks
{
	namespace Core
	{
		class Cocos2dxPlatform : public IGSPlatform
		{
			public:
				Cocos2dxPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool usePreviewServer, bool verboseLogging=false)
				: IGSPlatform(apikey, secret, usePreviewServer, verboseLogging)
				{}

				//Gets a unique identifier for the device
				virtual gsstl::string GetDeviceId() const
				{
					// TODO: implement
					return "NOT-IMPLEMENTED";
				}

				//IOS or AND or WP8 - Required for in app purchases
				virtual gsstl::string GetDeviceOS() const
				{
					#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
							return "OSX";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
							return "iOS";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
							return "Android";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
							return "Win32";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
							return "Linux";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE
							return "Marmelade";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_BADA
							return "Bada";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY
							return "Blackberry";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_NACL
							return "NaCl";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_EMSCRIPTEN
							return "emscripten";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN
							return "Tizen";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_QT5
							return "QTS";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
							return "WinRT";
					#elif CC_TARGET_PLATFORM == CC_PLATFORM_WP8
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
				virtual gsstl::string GetSDK() const
				{
					return "GameSparks SDK C++ 1.0 for Cocos2d-x";
				}

				//Will be used in analytics reports
				virtual gsstl::string GetDeviceType() const
				{
					// TODO: implement
					return "Cocos2d-x";
				}

				//Receives debugging information from the API
				virtual void DebugMsg(const gsstl::string& message) const
				{
					cocos2d::log("[GameSparks]: %s", message.c_str());
				}
		};
	}
}

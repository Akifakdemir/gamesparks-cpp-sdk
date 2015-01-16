#pragma once

#include "Platform.h"
#include <GameSparks/IGSPlatform.h>
#include "GameSparksModule.h"

namespace GameSparks
{
	namespace UnrealEngineSDK
	{
		class GSUnrealPlatform : public GameSparks::Core::IGSPlatform
		{
		public:
			GSUnrealPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool previewServer)
				: GameSparks::Core::IGSPlatform(apikey, secret, previewServer)
			{
			}

			virtual gsstl::string GetDeviceId() const
			{
				return TCHAR_TO_ANSI(*FPlatformMisc::GetUniqueDeviceId());
			}

			virtual gsstl::string GetDeviceOS() const
			{
				return FPlatformProperties::IniPlatformName();
			}

			virtual gsstl::string GetPlatform() const
			{
				return FPlatformProperties::PlatformName();
			}

			virtual gsstl::string GetSDK() const
			{
				return "GameSparks Unreal Engine SDK";
			}

			virtual gsstl::string GetDeviceType() const
			{
#if PLATFORM_DESKTOP
				return "Desktop";
#else
				return "Handheld";
#endif	
			}

			virtual bool GetExtraDebug() const
			{
				return true;
			}

			virtual gsstl::string GetPreviewServiceUrl() const
			{
				return "wss://preview.gamesparks.net/ws/" + m_apiKey;
			}

			virtual gsstl::string GetLiveServiceUrl() const
			{
				return "wss://preview.gamesparks.net/ws/" + m_apiKey;
			}

			virtual void DebugMsg(const gsstl::string& message) const
			{
				if (UGameSparksModule::GetModulePtr())
					UGameSparksModule::GetModulePtr()->SendDebugLogToComponents(message);
			}
		};
	}
}
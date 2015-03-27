// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.

#ifndef Cocos2dxPlatform_h__
#define Cocos2dxPlatform_h__

#pragma once

#include "./IGSPlatform.h"

#ifndef CC_TARGET_PLATFORM
#	error "This file is meant for inclusion in Cocos2d-x projects only. Please make sure, that this file is included AFTER the Cocos2d-x headers."
#endif /* CC_TARGET_PLATFORM */

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
#endif // Cocos2dxPlatform_h__

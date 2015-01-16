#pragma once

#include "cJSON.h"

namespace GameSparks
{
	namespace Core
	{
		class IGSData
		{
		public:

			virtual const cJSON* GetBaseData() const = 0;
		};
	}

}
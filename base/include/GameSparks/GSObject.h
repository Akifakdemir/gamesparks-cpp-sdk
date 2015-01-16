#pragma once

#include "GSRequestData.h"
#include "GSOptional.h"
#include "cJSON.h"

namespace GameSparks
{
	namespace Core
	{
		class GSRequest;

		class GSObject : public GSRequestData
		{
		public:

			typedef GameSparks::Optional::Optional_<GSObject> t_Optional;
			
			GSObject(cJSON* data)
				: GSRequestData(data)
			{
	
			}
	
			GSObject(const GSData& wrapper)
				: GSRequestData(wrapper)
			{

			}

			GSObject(const GSObject& other)
				: GSRequestData(other.m_Data)
			{

			}

			

			~GSObject()
			{
			}
	
			GSObject(const gsstl::string& type)
			{
				AddString("@class", type);
			}
	
			Optional::t_StringOptional GetType() const
			{
				return GetString("@class");
			}
	
			static GSObject FromJSON(const gsstl::string& json)
			{
				cJSON* root = cJSON_Parse(json.c_str());
				GSObject result(root);
				cJSON_Delete(root);
				return result;
			}
	
		protected:
			GSObject()
				: GSRequestData()
			{
				
			}

			friend class GSRequest;
		};
	}
}
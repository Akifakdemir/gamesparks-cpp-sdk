// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSRequestData_h__
#define GSRequestData_h__

#pragma once

#include "GSData.h"
#include <GameSparks/GSDateTime.h>

namespace GameSparks
{
	namespace Core
	{
		class GSRequestData : public GSData
		{
            GS_LEAK_DETECTOR(GSRequestData);
            
		public:
			GSRequestData() : GSData() {}

			/*GSRequestData(const gsstl::string& jsonString)
			{
			}*/

			GSRequestData(const GSData& wrapper) : GSData(wrapper)
			{
			}

			GSRequestData(const GSRequestData& other)
				: GSData(other.m_Data)
			{

			}

			GSRequestData(cJSON* data) : GSData(data){}

			

			virtual GSRequestData& AddString(const gsstl::string& paramName, const gsstl::string& value)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_CreateString(value.c_str()));
				return *this;
			}

			virtual GSRequestData& AddJSONStringAsObject(const gsstl::string& paramName, const gsstl::string& jsonString)
			{
				cJSON* obj = cJSON_Parse(jsonString.c_str());
				cJSON_AddItemToObject(m_Data, paramName.c_str(), obj);
				return *this;
			}

			virtual GSRequestData& AddDate(const gsstl::string& paramName, const GSDateTime& date)
			{
				AddString(paramName, date.ToString());
				return *this;
			}

			virtual GSRequestData& AddNumber(const gsstl::string& paramName, long value)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_CreateNumber(value));
				return *this;
			}

			virtual GSRequestData& AddNumberList(const gsstl::string& paramName, const gsstl::vector<long>& child)
			{
				cJSON* json_array = cJSON_CreateArray();
				for (gsstl::vector<long>::const_iterator it = child.begin(); it != child.end(); ++it)
				{
					cJSON_AddItemToArray(json_array, cJSON_CreateNumber(*it));
				}
				cJSON_AddItemToObject(m_Data, paramName.c_str(), json_array);
				return *this;
			}

			virtual GSRequestData& AddNumber(const gsstl::string& paramName, float value)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_CreateNumber(value));
				return *this;
			}

			virtual GSRequestData& AddNumberList(const gsstl::string& paramName, const gsstl::vector<float>& child)
			{
				cJSON* json_array = cJSON_CreateArray();
				for (gsstl::vector<float>::const_iterator it = child.begin(); it != child.end(); ++it)
				{
					cJSON_AddItemToArray(json_array, cJSON_CreateNumber(*it));
				}
				cJSON_AddItemToObject(m_Data, paramName.c_str(), json_array);
				return *this;
			}

			virtual GSRequestData& AddNumber(const gsstl::string& paramName, double value)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_CreateNumber(value));
				return *this;
			}

			virtual GSRequestData& AddNumberList(const gsstl::string& paramName, const gsstl::vector<double>& child)
			{
				cJSON* json_array = cJSON_CreateArray();
				for (gsstl::vector<double>::const_iterator it = child.begin(); it != child.end(); ++it)
				{
					cJSON_AddItemToArray(json_array, cJSON_CreateNumber(*it));
				}
				cJSON_AddItemToObject(m_Data, paramName.c_str(), json_array);
				return *this;
			}

			virtual GSRequestData& AddNumber(const gsstl::string& paramName, int value)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_CreateNumber(value));
				return *this;
			}

			virtual GSRequestData& AddNumberList(const gsstl::string& paramName, const gsstl::vector<int>& child)
			{
				cJSON* json_array = cJSON_CreateArray();
				for (gsstl::vector<int>::const_iterator it = child.begin(); it != child.end(); ++it)
				{
					cJSON_AddItemToArray(json_array, cJSON_CreateNumber(*it));
				}
				cJSON_AddItemToObject(m_Data, paramName.c_str(), json_array);
				return *this;
			}

			virtual GSRequestData& AddObject(const gsstl::string& paramName, const GSData& child)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_Duplicate(child.GetBaseData(), 1));
				return *this;
			}

			virtual GSRequestData& AddObjectList(const gsstl::string& paramName, const gsstl::vector<GSData>& child)
			{
				cJSON* json_array = cJSON_CreateArray();
				for (gsstl::vector<GSData>::const_iterator it = child.begin(); it != child.end(); ++it)
				{
					cJSON_AddItemToArray(json_array, cJSON_Duplicate(it->GetBaseData(), 1));
				}
				cJSON_AddItemToObject(m_Data, paramName.c_str(), json_array);
				return *this;
			}

			virtual GSRequestData& AddStringList(const gsstl::string& paramName, const gsstl::vector<gsstl::string>& child)
			{
				cJSON* json_array = cJSON_CreateArray();
				for (gsstl::vector<gsstl::string>::const_iterator it = child.begin(); it != child.end(); ++it)
				{
					cJSON_AddItemToArray(json_array, cJSON_CreateString(it->c_str()));
				}
				cJSON_AddItemToObject(m_Data, paramName.c_str(), json_array);
				return *this;
			}

			virtual GSRequestData& AddBoolean(const gsstl::string& paramName, bool value)
			{
				cJSON_AddItemToObject(m_Data, paramName.c_str(), cJSON_CreateBool(value ? 1 : 0));
				return *this;
			}
		};
	}
}
#endif // GSRequestData_h__
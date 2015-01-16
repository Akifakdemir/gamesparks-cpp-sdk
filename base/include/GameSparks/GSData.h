#pragma once

#include "IGSData.h"
#include "GSOptional.h"
#include "GSDateTime.h"


namespace GameSparks
{
	namespace Core
	{
		class GSData : public IGSData
		{
		public:
			typedef GameSparks::Optional::Optional_<GSData> t_Optional;

			GSData()
			{
				m_Data = cJSON_CreateObject();
			}

			GSData(const GSData& other)
			{
				m_Data = cJSON_Duplicate(other.m_Data, 1);
			}

			GSData(cJSON* data)
			{
				m_Data = cJSON_Duplicate(data, 1);
				// whatever here makes sense (o:
			}

			~GSData()
			{
				cJSON_Delete(m_Data);
			}

			GSData& operator=(GSData other)
			{
				m_Data = cJSON_Duplicate(other.m_Data, 1);
				return *this;
			}

			virtual bool ContainsKey(const gsstl::string& key) const
			{
				return (cJSON_GetObjectItem(m_Data, key.c_str()) != 0);
			}

			virtual Optional::t_StringOptional GetString(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_String)
					return Optional::t_StringOptional(gsstl::string(item->valuestring), true);
				else
					return Optional::t_StringOptional(gsstl::string(), false);
			}

			virtual Optional::t_IntOptional GetInt(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_Number)
					return Optional::t_IntOptional(item->valueint, true);
				else
					return Optional::t_IntOptional(0, false);
			}

			virtual Optional::t_LongOptional GetLong(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_Number)
					return Optional::t_LongOptional(item->valueint, true);
				else
					return Optional::t_LongOptional(0, false);
			}

			virtual Optional::t_LongOptional GetNumber(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_Number)
					return Optional::t_LongOptional(item->valueint, true);
				else
					return Optional::t_LongOptional(0, false);
			}

			virtual Optional::t_DoubleOptional GetDouble(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_Number)
					return Optional::t_DoubleOptional(item->valuedouble, true);
				else
					return Optional::t_DoubleOptional((double)0, false);
			}

			virtual Optional::t_FloatOptional GetFloat(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_Number)
					return Optional::t_FloatOptional(static_cast<float>(item->valuedouble), true);
				else
					return Optional::t_FloatOptional((float)0, false);
			}

			virtual Optional::t_BoolOptional GetBoolean(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_True)
					return Optional::t_BoolOptional(true, true);
				else if (item != NULL && item->type == cJSON_False)
					return Optional::t_BoolOptional(false, true);
				else
					return Optional::t_BoolOptional(false, false);
			}

			virtual t_Optional GetGSDataObject(const gsstl::string& name) const
			{
				cJSON* item = cJSON_GetObjectItem(m_Data, name.c_str());
				if (item != NULL && item->type == cJSON_Object)
					return t_Optional(GSData(item), true);
				else
					return t_Optional(GSData(), false);
			}

			virtual GSDateTime::t_Optional GetDate(const gsstl::string& name) const
			{
				Optional::t_StringOptional dateString = GetString(name);
				if (dateString.HasValue())
				{
					return GSDateTime::t_Optional(GSDateTime(dateString.GetValue()), true);
				}
				else
				{
					return GSDateTime::t_Optional(GSDateTime(), false);
				}
			}

			virtual gsstl::vector<gsstl::string> GetStringList(const gsstl::string& name) const
			{
				gsstl::vector<gsstl::string> result;
				cJSON* arr = cJSON_GetObjectItem(m_Data, name.c_str());
				if (arr != NULL && arr->type == cJSON_Array)
				{
					for (int i = 0; i < cJSON_GetArraySize(arr); ++i)
					{
						cJSON* item = cJSON_GetArrayItem(arr, i);
						if (item != NULL && item->type == cJSON_String)
						{
							result.push_back(gsstl::string(item->valuestring));
						}
					}
				}
				return result;
			}

			virtual gsstl::vector<float> GetFloatList(const gsstl::string& name) const
			{
				gsstl::vector<float> result;
				cJSON* arr = cJSON_GetObjectItem(m_Data, name.c_str());
				if (arr != NULL && arr->type == cJSON_Array)
				{
					for (int i = 0; i < cJSON_GetArraySize(arr); ++i)
					{
						cJSON* item = cJSON_GetArrayItem(arr, i);
						if (item != NULL && item->type == cJSON_Number)
						{
							result.push_back((float)item->valuedouble);
						}
					}
				}
				return result;
			}

			virtual gsstl::vector<double> GetDoubleList(const gsstl::string& name) const
			{
				gsstl::vector<double> result;
				cJSON* arr = cJSON_GetObjectItem(m_Data, name.c_str());
				if (arr != NULL && arr->type == cJSON_Array)
				{
					for (int i = 0; i < cJSON_GetArraySize(arr); ++i)
					{
						cJSON* item = cJSON_GetArrayItem(arr, i);
						if (item != NULL && item->type == cJSON_Number)
						{
							result.push_back(item->valuedouble);
						}
					}
				}
				return result;
			}

			virtual gsstl::vector<int> GetIntList(const gsstl::string& name) const
			{
				gsstl::vector<int> result;
				cJSON* arr = cJSON_GetObjectItem(m_Data, name.c_str());
				if (arr != NULL && arr->type == cJSON_Array)
				{
					for (int i = 0; i < cJSON_GetArraySize(arr); ++i)
					{
						cJSON* item = cJSON_GetArrayItem(arr, i);
						if (item != NULL && item->type == cJSON_Number)
						{
							result.push_back(item->valueint);
						}
					}
				}
				return result;
			}

			virtual gsstl::vector<long> GetLongList(const gsstl::string& name) const
			{
				gsstl::vector<long> result;
				cJSON* arr = cJSON_GetObjectItem(m_Data, name.c_str());
				if (arr != NULL && arr->type == cJSON_Array)
				{
					for (int i = 0; i < cJSON_GetArraySize(arr); ++i)
					{
						cJSON* item = cJSON_GetArrayItem(arr, i);
						if (item != NULL && item->type == cJSON_Number)
						{
							result.push_back((long)item->valueint);
						}
					}
				}
				return result;
			}


			virtual gsstl::vector<GSData> GetGSDataObjectList(const gsstl::string& name) const
			{
				gsstl::vector<GSData> result;
				cJSON* arr = cJSON_GetObjectItem(m_Data, name.c_str());
				if (arr != NULL && arr->type == cJSON_Array)
				{
					for (int i = 0; i < cJSON_GetArraySize(arr); ++i)
					{
						result.push_back(GSData(cJSON_GetArrayItem(arr, i)));
					}
				}
				return result;
			}

			virtual cJSON* GetBaseData() const
			{
				return m_Data;
			}

			virtual gsstl::string GetJSON() const
			{
				char* asText = cJSON_Print(m_Data);
				gsstl::string result(asText);
				free(asText);
				return result;
			}


		protected:
			cJSON* m_Data;
		};
	}	
}

// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSData_h__
#define GSData_h__

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

			GSData();

			GSData(const GSData& other);

			GSData(cJSON* data);

			virtual ~GSData();

			GSData& operator=(GSData other);

			virtual bool ContainsKey(const gsstl::string& key) const;

			
			virtual Optional::t_StringOptional GetString(const gsstl::string& name) const;

			virtual Optional::t_IntOptional GetInt(const gsstl::string& name) const;

			virtual Optional::t_LongOptional GetLong(const gsstl::string& name) const;

			virtual Optional::t_LongOptional GetNumber(const gsstl::string& name) const;

			virtual Optional::t_DoubleOptional GetDouble(const gsstl::string& name) const;

			virtual Optional::t_FloatOptional GetFloat(const gsstl::string& name) const;

			virtual Optional::t_BoolOptional GetBoolean(const gsstl::string& name) const;

			virtual t_Optional GetGSDataObject(const gsstl::string& name) const;

			virtual GSDateTime::t_Optional GetDate(const gsstl::string& name) const;

			virtual gsstl::vector<gsstl::string> GetStringList(const gsstl::string& name) const;

			virtual gsstl::vector<float> GetFloatList(const gsstl::string& name) const;

			virtual gsstl::vector<double> GetDoubleList(const gsstl::string& name) const;

			virtual gsstl::vector<int> GetIntList(const gsstl::string& name) const;

			virtual gsstl::vector<long> GetLongList(const gsstl::string& name) const;


			virtual gsstl::vector<GSData> GetGSDataObjectList(const gsstl::string& name) const;

			virtual cJSON* GetBaseData() const;

			virtual gsstl::string GetJSON() const;


		protected:
			cJSON* m_Data;
            
            GS_LEAK_DETECTOR(GSData);
		};
	}	
}
#endif // GSData_h__

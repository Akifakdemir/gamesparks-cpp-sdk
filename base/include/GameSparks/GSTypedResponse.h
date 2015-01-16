#pragma once

#include "GSData.h"

namespace GameSparks
{
	namespace Core
	{
		 class GSTypedResponse
		 {
		 protected:
			 const static gsstl::string SCRIPT_DATA_KEY;
			 const static gsstl::string ERROR_KEY;
			 const static gsstl::string REQUEST_ID_KEY;
		 public:
			
			 // declare this class as abstract without other pure virtual functions
			 //virtual ~GSTypedResponse() = 0;

			GSTypedResponse(const GSData& response)
				: m_Response(response)
			{
			}

			GSTypedResponse(const GSTypedResponse& other)
				: m_Response(other.m_Response)
			{

			}

			gsstl::string GetJSONString() const
			{
				return m_Response.GetJSON();
			}

			const cJSON* GetJSONData() const
			{
				return m_Response.GetBaseData();
			}

			GSData::t_Optional GetScriptData() const
			{
				return m_Response.GetGSDataObject(SCRIPT_DATA_KEY);
			}
		
			bool GetHasErrors() const
			{
				return m_Response.ContainsKey(ERROR_KEY);
			}

			GSData::t_Optional GetErrors() const
			{
				return m_Response.GetGSDataObject(ERROR_KEY);
			}

			Optional::t_StringOptional GetRequestId() const
			{
				return m_Response.GetString(REQUEST_ID_KEY);
			}

			const GSData& GetBaseData() const
			{
				return m_Response;
			}
		 protected:
			 GSData m_Response;
		 };
	}
}
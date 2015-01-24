<#include "_GS_Macros.ftl"/>
#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSObject.h"
#include "../GSTypedResponse.h"
#include "../GSTypedRequest.h"
#include "GSResponses.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Requests
		{
<#list requestDocumentationMetaData.rootClasses as classData>
			class ${classData.friendlyClassName} : public GameSparks::Core::GSTypedRequest < ${classData.friendlyClassName}, GameSparks::Api::Responses::${classData.baseResponseType.friendlyClassName} >
			{
			public:
				${classData.friendlyClassName}(Core::GS_& gsInstance)
					: GSTypedRequest(gsInstance, ".${classData.friendlyClassName}")
				{

				}
			

			<#if classData.friendlyClassName == "LogEventRequest" || classData.friendlyClassName == "LogChallengeEventRequest">
				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, long value)
				{
					m_Request.AddNumber(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, int value)
				{
					m_Request.AddNumber(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, const gsstl::string& value)
				{
					m_Request.AddString(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, const GameSparks::Core::GSRequestData& value)
				{
					m_Request.AddObject(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, gsstl::vector<GameSparks::Core::GSData> value)
				{
					m_Request.AddObjectList(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, gsstl::vector<gsstl::string> value)
				{
					m_Request.AddStringList(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, gsstl::vector<long> value)
				{
					m_Request.AddNumberList(key, value);
					return *this;
				}

				${classData.friendlyClassName}& SetEventAttribute(const gsstl::string& key, gsstl::vector<int> value)
				{
					m_Request.AddNumberList(key, value);
					return *this;
				}
			</#if>

			<#list classData.methodMetaData as param>
			<#if !param.getCodeGenMeta("unity", "hide")??>
			/// <summary>
			<#list param.description as description>
			/// ${description}
			</#list>
			/// </summary>
			${classData.friendlyClassName}& Set${param.propertyName?cap_first}( <@paramSetType param.returnType.friendlyClassName/> ${param.propertyName} )
			{
				m_Request.<@paramAddMethod param.returnType.friendlyClassName/>("${param.propertyName}", ${param.propertyName});
				return *this;
			}
			</#if>
			</#list>
			};
			
</#list>
		}
	}
}





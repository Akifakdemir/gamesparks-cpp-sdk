<#include "_GS_Macros.ftl"/>
#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSTypedResponse.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Responses
		{
<#list responseDocumentationMetaData.rootClasses as responseClass>
			class ${responseClass.friendlyClassName} : public  GameSparks::Core::GSTypedResponse
			{
			public:
				${responseClass.friendlyClassName}(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				${responseClass.friendlyClassName}(const ${responseClass.friendlyClassName}& other)
					: GSTypedResponse(other)
				{
				}

				<@renderMethods responseDocumentationMetaData responseClass/>
			};
</#list>
		}
	}
}

<#macro renderMethods documentationMetaData responseClass>
	<#list responseClass.returnTypes as returnType>
	<#if returnType.isGameSparksType() && returnType.friendlyClassName != "ScriptData"> 
		class _${returnType.friendlyClassName} : public GSTypedResponse
		{
		public:
			_${returnType.friendlyClassName}(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			<@renderMethods documentationMetaData returnType/>
			
			<#if returnType.friendlyClassName = "LeaderboardData">
			GameSparks::Optional::t_LongOptional GetNumberValue(const gsstl::string& key)
			{
				return m_Response.GetLong(key);
			}
			
			GameSparks::Optional::t_StringOptional GetStringValue(const gsstl::string& key)
			{
				return m_Response.GetString(key);
			}
			</#if>
		};
	</#if>
	</#list>
	<#list responseClass.methodMetaData as getterMetaData>
		<#if getterMetaData.fullMethodName != "getScriptData" && getterMetaData.fullMethodName != "getRequestId">
			/// <summary>
			<#list getterMetaData.description as description>
			/// ${description}
			</#list>
			/// </summary>
			<#if systemMetaData.getClass(getterMetaData.returnType.name)?? && systemMetaData.getClass(getterMetaData.returnType.name).isGameSparksType()>
				<#if getterMetaData.collection>
					<#assign returnTypeClassMetaData = systemMetaData.getClass(getterMetaData.returnType.name)>
					// method type 1
					gsstl::vector<_${returnTypeClassMetaData.friendlyClassName}> Get${getterMetaData.propertyName?cap_first}() const
					{
						gsstl::vector<_${returnTypeClassMetaData.friendlyClassName}> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("${getterMetaData.methodName}");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_${returnTypeClassMetaData.friendlyClassName}(*it));
						}
						return result; 
					}
				<#else>
					// method type 2
					<#assign returnTypeClassMetaData = systemMetaData.getClass(getterMetaData.returnType.name)>
					_${returnTypeClassMetaData.friendlyClassName} Get${getterMetaData.propertyName?cap_first}() const
					{
						return _${returnTypeClassMetaData.friendlyClassName}(m_Response.GetGSDataObject("${getterMetaData.propertyName}").GetValue());
					}
				</#if>
			<#else>
				<#if getterMetaData.collection>
					<#if systemMetaData.getClass(getterMetaData.returnType.name).isGameSparksType() || getterMetaData.returnType.friendlyClassName == "Map">
						// method type 3.1 
						gsstl::vector<<@paramType getterMetaData.returnType.friendlyClassName/>> Get${getterMetaData.propertyName?cap_first}() const
						{
							gsstl::vector<<@paramType getterMetaData.returnType.friendlyClassName/>> result;
							gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("${getterMetaData.methodName}");
							for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
							{
								result.push_back(<@paramType getterMetaData.returnType.friendlyClassName/>(*it, true));
							}
							return result;
						}
					<#elseif getterMetaData.returnType.friendlyClassName == "String">
						gsstl::vector<gsstl::string> Get${getterMetaData.propertyName?cap_first}() const
						{
							return m_Response.GetStringList("${getterMetaData.methodName}");
						}
					<#elseif getterMetaData.returnType.friendlyClassName == "Float">
						gsstl::vector<float> Get${getterMetaData.propertyName?cap_first}() const
						{
							return m_Response.GetFloatList("${getterMetaData.methodName}");
						}
					<#elseif getterMetaData.returnType.friendlyClassName == "Integer">
						gsstl::vector<int> Get${getterMetaData.propertyName?cap_first}() const
						{
							return m_Response.GetIntList("${getterMetaData.methodName}");
						}
					<#elseif getterMetaData.returnType.friendlyClassName == "Long">
						gsstl::vector<long> Get${getterMetaData.propertyName?cap_first}() const
						{
							return m_Response.GetLongList("${getterMetaData.methodName}");
						}
					<#else>
						// method type 3.2 
						/*gsstl::vector<<@paramType getterMetaData.returnType.friendlyClassName/>> Get${getterMetaData.propertyName?cap_first}() const
						{
							gsstl::vector<<@paramType getterMetaData.returnType.friendlyClassName/>> result;
							gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("${getterMetaData.methodName}");
							for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
							{
								result.push_back(<@paramType getterMetaData.returnType.friendlyClassName/>(*it, true));
							}
							return result;
						}*/
					</#if>	
				<#else>
					// method type 4
					<@paramType getterMetaData.returnType.friendlyClassName/> Get${getterMetaData.propertyName?cap_first} () const
					{
						return m_Response.<@paramGetMethod getterMetaData.returnType.friendlyClassName/>("${getterMetaData.propertyName}");
					}
				</#if>
			</#if>
		</#if>
	</#list>
</#macro>
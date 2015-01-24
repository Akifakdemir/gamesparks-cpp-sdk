<#include "_GS_Macros.ftl"/>
#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSMessage.h"
#include "../gsstl.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Messages
		{
<#list messageDocumentationMetaData.rootClasses as responseClass>
			class ${responseClass.friendlyClassName} : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".${responseClass.friendlyClassName}";
					}

					${responseClass.friendlyClassName}(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
					<@renderMethods messageDocumentationMetaData responseClass/>
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
			_${returnType.friendlyClassName}(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
			<@renderMethods documentationMetaData returnType/>
		};
	</#if>
	</#list>
	<#list responseClass.methodMetaData as getterMetaData>
		<#if getterMetaData.fullMethodName != "getScriptData" && getterMetaData.fullMethodName != "getMessageId">
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
					// method type 3 
					gsstl::vector<<@paramType getterMetaData.returnType.friendlyClassName/>> Get${getterMetaData.propertyName?cap_first}() const
					{
						gsstl::vector<<@paramType getterMetaData.returnType.friendlyClassName/>> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("${getterMetaData.methodName}");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(<@paramType getterMetaData.returnType.friendlyClassName/>(*it));
						}
						return result;
					}
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
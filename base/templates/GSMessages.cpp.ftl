<#include "_GS_Macros.ftl"/>

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include <GameSparks/generated/GSMessages.h>

namespace GameSparks
{
	namespace Api
	{
		namespace Messages
		{
<#list messageDocumentationMetaData.rootClasses as responseClass>
			${responseClass.friendlyClassName}::t_ListenerFunction ${responseClass.friendlyClassName}::Listener;
</#list>
		}
	}
}
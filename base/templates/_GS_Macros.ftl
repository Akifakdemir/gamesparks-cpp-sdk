<#macro paramType type><#if 
	type == 'Long' || type='long'>GameSparks::Optional::t_LongOptional<#elseif
	type == 'Integer' || type='int'>GameSparks::Optional::t_IntOptional<#elseif  
	type == 'Float'>GameSparks::Optional::t_FloatOptional<#elseif
	type == 'Date'>GameSparks::Core::GSDateTime::t_Optional<#elseif
	type == 'String'>GameSparks::Optional::t_StringOptional<#elseif
	type == 'String[]'>gsstl::vector<GameSparks::Optional::t_StringOptional><#elseif  
	type == 'boolean'>GameSparks::Optional::t_BoolOptional<#elseif
	type == 'Map'>GameSparks::Core::GSData::t_Optional<#else
>DEFAULT ${type}</#if></#macro>

<#macro paramGetMethod type><#if 
	type == 'Map'>GetObject<#elseif 
	type == 'String[]'>GetStringList<#elseif 
	type == 'Date'>GetDate<#elseif
	type == 'Long' || type == 'long'>GetLong<#elseif
	type == 'Integer' || type == 'int'>GetInt<#elseif
	type == 'Float'>GetFloat<#elseif
	type == 'String'>GetString<#elseif
	type == 'boolean'>GetBoolean<#else
>DEFAULT ${type}</#if></#macro>

<#macro paramAddMethod type><#if 
	type == 'Map'>AddObject<#elseif
	type == 'UploadData'>AddObject<#elseif 
	type == 'String[]'>AddStringList<#elseif 
	type == 'Integer[]'>AddNumberList<#elseif 
	type == 'Integer'>AddNumber<#elseif 
	type == 'Long'>AddNumber<#elseif 
	type == 'int'>AddNumber<#elseif 
	type == 'long'>AddNumber<#elseif 
	type == 'Date'>AddDate<#elseif
	type == 'String'>AddString<#elseif 
	type == 'boolean'>AddBoolean<#elseif
	type == 'Boolean'>AddBoolean<#else
>DEFAULT ${type}</#if></#macro>

<#macro paramSetType type><#if 
	type == 'Long'>long<#elseif
	type == 'UploadData'>const GameSparks::Core::GSRequestData&<#elseif
	type == 'Integer'>long<#elseif  
	type == 'int'>long<#elseif  
	type == 'Date'>const GameSparks::Core::GSDateTime&<#elseif
	type == 'String'>const gsstl::string&<#elseif
	type == 'String[]'>gsstl::vector<gsstl::string><#elseif  
	type == 'Boolean'>bool<#elseif
	type == 'boolean'>bool<#elseif
	type == 'Map'>const GameSparks::Core::GSRequestData&<#else
>DEFAULT ${type}</#if></#macro>


#pragma once

#include "GSTypedResponse.h"
#include "GSObject.h"
#include "./gsstl.h"

using namespace GameSparks::Core;
using namespace GameSparks::Optional;

namespace GameSparks
{
	namespace Api
	{
		namespace Messages
		{
			 class GSMessage : public GSTypedResponse
			 {
			 protected:
				const static gsstl::string MESSAGE_ID_KEY;

				#if defined(GS_USE_STD_FUNCTION)
					typedef gsstl::function<void(const GSData&)> t_CreateMessageFunction;
				#else
					typedef void(*t_CreateMessageFunction)(const GSData&);
				#endif /* GS_USE_STD_FUNCTION */
				typedef gsstl::map<gsstl::string, t_CreateMessageFunction> t_CreateMessageFunctionMap;
				static t_CreateMessageFunctionMap m_Handlers;		 

			 public:
				 GSMessage(const GSData& message) 
					 : GSTypedResponse(message)
				 {
					 
				 }
				
				 t_StringOptional GetMessageId() const
				 {
					 return m_Response.GetString(MESSAGE_ID_KEY);
				 }
			 public:

				 static void NotifyHandlers(const GSObject& message)
				 {


					 t_CreateMessageFunctionMap::iterator find = m_Handlers.find(message.GetType().GetValue());
					 if (find != m_Handlers.end())
					 { 
						 find->second(message);
					 }
					 /*
					 internal static void NotifyHandlers(GSObject message){

					 if (message.ContainsKey("extCode")) {
					 if (handlers.ContainsKey(message.Type + "_" + message.GetString("extCode"))) {
					 handlers[message.Type + "_" + message.GetString("extCode")](message);
					 return;
					 }
					 }

					 if (handlers.ContainsKey(message.Type)) {
					 handlers[message.Type](message);
					 }
					 }

					 */
				 }
			 };
		}
	}
}
// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSMessage_h__
#define GSMessage_h__

#pragma once

#include "GSTypedResponse.h"
#include "GSObject.h"
#include "./gsstl.h"
#include <GameSparks/GSLeakDetector.h>

using namespace GameSparks::Core;
using namespace GameSparks::Optional;

namespace GameSparks
{
	namespace Core
	{
		class GS_;
	}

	namespace Api
	{
		namespace Messages
		{
			/// base class for all messages
			class GSMessage : public GSTypedResponse
			{
				public:
					/// construct from GSData
					GSMessage(const GSData& message) 
					: GSTypedResponse(message)
					{

					}

					/// get the id of this message
					t_StringOptional GetMessageId() const
					{
						return m_Response.GetString(MESSAGE_ID_KEY);
					}

				protected:
					/// @internal
					const static gsstl::string MESSAGE_ID_KEY; ///< key name to access the message id

					#if defined(GS_USE_STD_FUNCTION)
					/// create message function as a std::function
					typedef gsstl::function<void(const GSData&)> t_CreateMessageFunction;
					#else
					/// create message function as a c function pointer
					typedef void(*t_CreateMessageFunction)(const GSData&);
					#endif /* GS_USE_STD_FUNCTION */
					/// maps class name to factory function
					typedef gsstl::map<gsstl::string, t_CreateMessageFunction> t_CreateMessageFunctionMap;
					/// a static instance of the factory map
					static t_CreateMessageFunctionMap m_Handlers;
					/// @endinternal

				private:
					friend class Core::GS_;
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
#endif // GSMessage_h__
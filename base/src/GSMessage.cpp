// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#include <GameSparks/GSMessage.h>

namespace GameSparks
{
	namespace Api
	{
		namespace Messages
		{
			GSMessage::t_CreateMessageFunctionMap GSMessage::m_Handlers;
			const gsstl::string GSMessage::MESSAGE_ID_KEY = "messageId";

		}
	}
}
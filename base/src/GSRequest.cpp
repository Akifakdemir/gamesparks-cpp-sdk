// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#include <GameSparks/GS.h>
#include <GameSparks/GSRequest.h>
#include <cassert>

using namespace GameSparks;
using namespace GameSparks::Core;

GSRequest::GSRequest(GS& gsInstance, const gsstl::string& requestType)
	: m_GSInstance(&gsInstance) // use static instance if no instance was passed
	, m_Durable(false)
	, m_DurableRetrySeconds(1) // if the request is durable, we'll try to send it immediately
    , m_userData()
{
	AddString("@class", requestType);
}

GameSparks::Core::GSRequest::GSRequest(GS& gsInstance, cJSON* data)
	: GSObject(data)
	, m_GSInstance(&gsInstance) // use static instance if no instance was passed
	, m_DurableRetrySeconds(1) // if the request is durable, we'll try to send it immediately
    , m_userData()
{

}

bool GameSparks::Core::GSRequest::operator==(const GSRequest& other) const
{
	return GetJSON() == other.GetJSON();
}


void GameSparks::Core::GSRequest::Send(const BaseCallbacksPtr& callbacks, int timeoutSeconds)
{
    (void)(timeoutSeconds); // unused
	assert(callbacks);
	m_callbacks = callbacks;
	m_GSInstance->Send(*this);
	m_callbacks = 0; // release the callback, so that this GSRequest instance can be re-used - Note: a copy is inside m_GSInstance
}

void GameSparks::Core::GSRequest::Send()
{
	m_GSInstance->Send(*this);
}

void GameSparks::Core::GSRequest::Complete(const GSObject& response)
{
	m_Response = response;

	if (m_callbacks)
	{
		if (response.ContainsKey("error"))
		{
			m_callbacks->OnError(*m_GSInstance, response);
		}
		else
		{
			m_callbacks->OnSucess(*m_GSInstance, response);
		}
	}
}

// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#include <GameSparks/GS.h>
#include <GameSparks/GSRequest.h>
#include <cassert>

using namespace GameSparks;
using namespace GameSparks::Core;

GSRequest::GSRequest(GS_& gsInstance, const gsstl::string& requestType)
	: m_GSInstance(&gsInstance) // use static instance if no instance was passed
	, m_Completer()
	, m_Durable(false)
{
	// if these assertions fail, your compiler failed to initialize m_Callback et al. even though default initialization was requested via the initializer list 
	assert(!m_Completer);

	AddString("@class", requestType);
}

GameSparks::Core::GSRequest::GSRequest(GS_& gsInstance, cJSON* data)
	: GSObject(data)
	, m_GSInstance(&gsInstance) // use static instance if no instance was passed
{

}

void GameSparks::Core::GSRequest::Send(const BaseCallbacksPtr& callbacks, int timeoutSeconds)
{
	assert(callbacks);
	m_callbacks = callbacks;
	m_GSInstance->Send(*this);
	m_callbacks = 0; // release the callback, so that this GSRequest instance can be re-used
}

GameSparks::Core::GSObject GameSparks::Core::GSRequest::Send()
{
	m_GSInstance->Send(*this);
	return m_Response;
}

void GameSparks::Core::GSRequest::Complete(const GSObject& response)
{
	m_Response = response;

	if (m_Completer) m_Completer(response);

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

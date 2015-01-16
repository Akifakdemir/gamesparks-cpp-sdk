#include <GameSparks/GS.h>
#include <GameSparks/GSRequest.h>
#include <cassert>

using namespace GameSparks;
using namespace GameSparks::Core;

GSRequest::GSRequest(const gsstl::string& requestType, GS_* gsInstance /*= 0*/)
	: m_GSInstance(gsInstance ? gsInstance : &GS) // use static instance if no instance was passed
	, m_Completer()
	, m_Durable(false)
{
	// if these assertions fail, your compiler failed to initialize m_Callback et al. even though default initialization was requested via the initializer list 
	assert(!m_Completer);

	AddString("@class", requestType);
}

GameSparks::Core::GSRequest::GSRequest(cJSON* data)
	: GSObject(data)
	, m_GSInstance(&GS) // use static instance if no instance was passed
{

}

/*
GameSparks::Core::GSRequest::GSRequest(const GSRequest& other)
	: GSObject(other.m_Data)
{
	// BS: I think we should not need this, the auto-generated one should be fine
	// (we don't have any owned pointers)

	m_Response = other.m_Response;

	m_GSInstance = other.m_GSInstance;

	m_Callback = other.m_Callback;
	m_ErrorCallback = other.m_ErrorCallback;
	m_Completer = other.m_Completer;
	m_callerInstance = other.m_callerInstance;

	m_Durable = other.m_Durable;
	m_CancelTicks = other.m_CancelTicks;
	m_WaitForResponseTicks = other.m_WaitForResponseTicks;
	m_DurableRetryTicks = other.m_DurableRetryTicks;
}*/

GSRequestData& GameSparks::Core::GSRequest::AddString(const gsstl::string& paramName, const gsstl::string& value)
{
	GSObject::AddString(paramName, value);
	return *this;
}

GSRequestData& GameSparks::Core::GSRequest::AddDate(const gsstl::string& paramName, const GSDateTime& date)
{
	GSObject::AddDate(paramName, date);
	return *this;
}

GSRequestData& GameSparks::Core::GSRequest::AddNumber(const gsstl::string& paramName, long value)
{
	GSObject::AddNumber(paramName, value);
	return *this;
}

GSRequestData& GameSparks::Core::GSRequest::AddObject(const gsstl::string& paramName, const GSData& child)
{
	GSObject::AddObject(paramName, child);
	return *this;
}

GSRequestData& GameSparks::Core::GSRequest::AddObjectList(const gsstl::string& paramName, const gsstl::vector<GSData>& child)
{
	GSObject::AddObjectList(paramName, child);
	return *this;
}

GSRequestData& GameSparks::Core::GSRequest::AddStringList(const gsstl::string& paramName, const gsstl::vector<gsstl::string>& child)
{
	GSObject::AddStringList(paramName, child);
	return *this;
}

GSRequestData& GameSparks::Core::GSRequest::AddBoolean(const gsstl::string& paramName, bool value)
{
	GSObject::AddBoolean(paramName, value);
	return *this;
}

void GameSparks::Core::GSRequest::Send(BaseCallbacks* callbacks, int timeoutSeconds)
{
	assert(callbacks);
	assert(!m_callbacks && "you're calling Send() twice on the same request instance");
	m_callbacks = callbacks;
	m_GSInstance->Send(*this);
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
			m_callbacks->OnError(response);
		}
		else
		{
			m_callbacks->OnSucess(response);
		}
	}
}

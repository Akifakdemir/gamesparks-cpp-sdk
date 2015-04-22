// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.

#include <GameSparks/GS.h>
//#include <iostream>
#include <GameSparks/GSUtil.h>
//#include <sstream>
#include <GameSparks/GSMessage.h>
#include <cassert>
#include "easywsclient.hpp"

#include <stdio.h>
#ifdef WIN32
#	define snprintf _snprintf
#endif /* WIN32 */

using namespace GameSparks;
using namespace GameSparks::Core;
using namespace GameSparks::Api::Messages;

/*__declspec(dllexport) GS_ GameSparks::Core::GS = GS_();*/

GS_::GS_()
	: m_GSPlatform(NULL)
	, m_Ready(false)
	, m_Paused(false)
	, m_Initialized(false)
	, m_backOffForSeconds(0.0f)
	, m_SessionId("")
	, GameSparksAvailable()
{
	/*
		If this assertion fails, your compiler fails to initialize
		GameSparksAvailable, even though a default initialization was
		requested in the initializer list.
	*/
	assert( !GameSparksAvailable );
}

GS_::~GS_()
{
	for (t_ConnectionContainer::iterator it = m_Connections.begin(); it != m_Connections.end(); ++it)
	{
		delete *it;
	}
	m_Connections.clear();
    
    for(t_MessageHandlerMap::iterator i = m_MessageHandlers.begin(); i != m_MessageHandlers.end(); ++i)
    {
        delete i->second;
    }
    m_MessageHandlers.clear();
}

void GS_::Initialise(IGSPlatform* gSPlatform)
{
	m_Initialized = true;
	m_Paused = false;
	m_GSPlatform = gSPlatform;
	m_ServiceUrl = m_GSPlatform->GetServiceUrl();
	
#if defined(WINDOWS_PHONE8) || defined(WIN32)
	easywsclient::initEasyWSClient();
#else
	//_gsInitOutcome = true;
#endif

	m_Connections.push_back(new GSConnection(this, m_GSPlatform));
	DebugLog("Initialized");
}

void GameSparks::Core::GS_::ShutDown()
{
	//DebugLog("Shutdown");
	m_Initialized = false;
	m_Paused = true;
	Stop(true);
	// clear the connections
	//UpdateConnections(0);
}

void GameSparks::Core::GS_::NewConnection()
{
	if (!m_Paused)
	{
		DebugLog("Create new connection");
		Stop(false);
		gsstl::reverse(m_Connections.begin(), m_Connections.end());
		m_Connections.push_back(new GSConnection(this, m_GSPlatform));
		gsstl::reverse(m_Connections.begin(), m_Connections.end());
	}
}

void GS_::Stop(bool termiante)
{
	for (t_ConnectionContainer::iterator it = m_Connections.begin(); it != m_Connections.end(); ++it)
	{
		GSConnection* connection = *it;
		if (termiante) connection->Terminate();
		else connection->Stop();
	}


	SetAvailability(false);
}

void GS_::OnMessageReceived(const gsstl::string& message, GSConnection& connection)
{
	//std::cout << message.c_str() << std::endl;

	GSObject response = GSObject::FromJSON(message);

	if (response.ContainsKey("connectUrl"))
	{
		DebugLog("Received new connection url from gamesparks backend. Establishing new connection now.");
		m_ServiceUrl = response.GetString("connectUrl").GetValue();
		NewConnection();
	}

	if (response.ContainsKey("authToken"))
	{
		DebugLog("Received auth token");
		m_GSPlatform->SetAuthToken(response.GetString("authToken").GetValue());
	}

	if (response.GetType().HasValue())
	{
		if (response.GetType().GetValue() == ".AuthenticatedConnectResponse")
		{
			DebugLog("Handle authentication connect response with immediate handshake");
			Handshake(response, connection);
		}
		else
		{
			ProcessReceivedItem(response, &connection);
		}
	}


	//std::cout << "@class: " << response.GetType().first.c_str() << std::endl;
	//std::cout << "@class: " << response.GetJSON().c_str() << std::endl;
}



void GameSparks::Core::GS_::Handshake(GSObject& response, GSConnection& connection)
{
	if (response.ContainsKey("error"))
	{
		// this method can be called indirectly from the websockets _dispatch member function
		// if we'd call shutdown here, we'd delete the socket, while a member function of of the
		// web socket is still on the callstack. Therefore we defer the shutdown
		m_backOffForSeconds = 5.0f;

		DebugLog("Got error during handshake. Please make sure, that you've setup you credentials.");
		DebugLog("Backing off for five seconds");
	}
	else if (response.ContainsKey("nonce"))
	{
		SendHandshake(response, connection);
	}
	else
	{
		if (response.ContainsKey("sessionId"))
		{
			m_SessionId = response.GetString("sessionId").GetValue();
			if (response.ContainsKey("authToken"))
			{
				m_GSPlatform->SetAuthToken(response.GetString("authToken").GetValue());
			}
			else
			{
				m_GSPlatform->SetAuthToken("0");
			}
			connection.SetReady(true);
			SetAvailability(true);
		}
	}
}

void GameSparks::Core::GS_::SendHandshake(GSObject& response, GSConnection& connection)
{
	GSRequest handshakeRequest(*this, ".AuthenticatedConnectRequest");
	handshakeRequest.AddString("hmac", GameSparks::Util::getHMAC(response.GetString("nonce").GetValue(), m_GSPlatform->GetGameSparksSecret()));
	handshakeRequest.AddString("os", m_GSPlatform->GetDeviceOS());
	handshakeRequest.AddString("platform", m_GSPlatform->GetPlatform());
	handshakeRequest.AddString("deviceId", m_GSPlatform->GetDeviceId());
	
	if (m_GSPlatform->GetAuthToken() != "" && m_GSPlatform->GetAuthToken() != "0")
	{
		handshakeRequest.AddString("authToken", m_GSPlatform->GetAuthToken());
	}

	if (m_SessionId != "")
	{
		handshakeRequest.AddString("sessionId", m_SessionId);
	}

	connection.SendImmediate(handshakeRequest);
	DebugLog("Handshake request sent");
}

void GameSparks::Core::GS_::Send(GSRequest& request)
{
	/*if (request.GetDurable())
	{
		SendDurable(request);
		return;
	}*/

	if (request.GetCancelSeconds() == 0)
	{
		request.SetCancelSeconds(m_GSPlatform->GetRequestTimeoutSeconds());
	}
	request.SetWaitForResponseSeconds(m_GSPlatform->GetRequestTimeoutSeconds());

	if (m_Connections.size() == 0)
	{
		NewConnection();
	}

	if (m_Connections.size() > 0 && m_Connections[0]->GetReady())
	{
		m_Connections[0]->SendImmediate(request);
		return;
	}

	m_SendQueue.push_back(request);
}

void GS_::Update(Seconds deltaTimeInSeconds)
{
	if (m_backOffForSeconds > 0)
	{
		m_backOffForSeconds -= deltaTimeInSeconds;
	}
	else if (m_Initialized)
	{
		UpdateConnections(deltaTimeInSeconds);
		ProcessQueues(deltaTimeInSeconds);
	}
}

void GameSparks::Core::GS_::DebugLog(const gsstl::string& message)
{
	m_GSPlatform->DebugMsg(message);
}

void GS_::UpdateConnections(Seconds deltaTimeInSeconds)
{
	for (t_ConnectionContainer::size_type i = 0; i < m_Connections.size(); )
	{
		GSConnection* connection = m_Connections[i];

		//size_t numConnections = m_Connections.size();
		connection->Update(deltaTimeInSeconds);

		// connection->Update might indirectly call OnWebSocketClientError, which creates a new connection
		//if (numConnections != m_Connections.size())
		//	break;

		// delete a finished websocket
		if (connection->IsWebSocketConnectionAlive() == false)
		{
			m_Connections.erase(m_Connections.begin() + i);
			delete connection;
		}
		else
		{
			++i;
		}
	}
}

gsstl::string GameSparks::Core::GS_::GetUniqueRequestId()
{
	static char buffer[256];
	snprintf(buffer, sizeof(buffer)/sizeof(buffer[0]), "_%ld", m_RequestCounter++);
	return gsstl::string(buffer);
}

void GameSparks::Core::GS_::OnWebSocketClientError(const gsstl::string& errorMessage, GSConnection* connection)
{
	DebugLog("Received websocket error: " + errorMessage);
	DebugLog("Got websocket error. Please make sure, that you've setup you credentials.");
	DebugLog("Backing off for five seconds");
	SetAvailability(false);
	m_backOffForSeconds = 5.0f;
}

void GameSparks::Core::GS_::SetAvailability(bool available)
{
	if (m_Ready != available)
	{
		m_Ready = available;
		
		if (GameSparksAvailable)
		{
			GameSparksAvailable(*this, available);
		}
	}
}

void GameSparks::Core::GS_::ConnectIfRequired()
{
	if (m_Connections.size() == 0)
	{
		NewConnection();
	}
}

bool GameSparks::Core::GS_::GetAuthenticated() const
{
	return m_Ready && m_GSPlatform->GetAuthToken() != "" && m_GSPlatform->GetAuthToken() != "0";
}

/*void GameSparks::Core::GS_::SendDurable(GSRequest& request)
{

}*/

void GameSparks::Core::GS_::ProcessSendQueue(Seconds deltaTimeInSeconds)
{
	if (m_SendQueue.size() > 0)
	{
		GSRequest& request = *m_SendQueue.begin();
		
		if (request.GetCancelSeconds() <= 0)
		{
			CancelRequest(request); // needs to be called, before it's popped from the queue
			m_SendQueue.pop_front();
		}

		if (m_Connections.size() > 0 && m_Connections[0]->GetReady())
		{
			m_Connections[0]->SendImmediate(request);
			m_SendQueue.pop_front();
		}

		request.SetCancelSeconds(request.GetCancelSeconds() - deltaTimeInSeconds);
	}
}

void GameSparks::Core::GS_::CancelRequest(GSRequest& request)
{
	GSObject error("ClientError");
	error.AddObject("error", GSRequestData().AddString("error", "timeout"));
	error.AddString("requestId", request.GetString("requestId").GetValue());

	request.Complete(error);
}

void GameSparks::Core::GS_::CancelRequest(GSRequest& request, GSConnection* connection)
{
	GSObject error("ClientError");
	error.AddObject("error", GSRequestData().AddString("error", "timeout"));
	error.AddString("requestId", request.GetString("requestId").GetValue());
	ProcessReceivedRepsonse(error, connection);
}

void GameSparks::Core::GS_::ProcessQueues(Seconds deltaTimeInSeconds)
{
	ConnectIfRequired();

	TrimOldConnections();
	ProcessSendQueue(deltaTimeInSeconds);
}

void GameSparks::Core::GS_::TrimOldConnections()
{
	for (t_ConnectionContainer::iterator it = m_Connections.begin(); it != m_Connections.end(); )
	{
		GSConnection* connection = *it;

		if (connection->m_PendingRequests.size() == 0 && connection->m_Stopped)
		{
			connection->Close();
			it = m_Connections.erase(it);
			delete connection;
		}
		else
		{
			++it;
		}
	}
}

void GameSparks::Core::GS_::ProcessReceivedRepsonse(const GSObject& response, GSConnection* connection)
{
	if (response.GetString("requestId").HasValue())
	{
		gsstl::string requestId = response.GetString("requestId").GetValue();
		
		GSConnection::t_RequestMap::iterator findIt = connection->m_PendingRequests.find(requestId);
		if (findIt != connection->m_PendingRequests.end())
		{
			GSRequest request = findIt->second;
			connection->m_PendingRequests.erase(findIt);

			if (request.GetDurableRetrySeconds() > 0)
			{
				// remove from persistent queue
			}

			request.Complete(response);
		}
	}

}

bool StringEndsWith(const gsstl::string& str, const gsstl::string& pattern)
{
	return  (str.size() >= pattern.size() && str.substr(str.size() - pattern.size()) == pattern);
}

void GameSparks::Core::GS_::ProcessReceivedItem(const GSObject& response, GSConnection* connection)
{
	gsstl::string responseType = response.GetType().GetValue();
	
	if (StringEndsWith(responseType, "Response"))
	{
		ProcessReceivedRepsonse(response, connection);
	}
	else if (StringEndsWith(responseType, "Message"))
	{
		GSMessage::NotifyHandlers(response);
	}
}

void GameSparks::Core::GS_::Disconnect()
{
	m_Paused = true;
	Stop(false);
}

void GameSparks::Core::GS_::Reconnect()
{
	m_Paused = false;
	ConnectIfRequired();
}

void GameSparks::Core::GS_::NetworkChange(bool available)
{
	if (available)
	{
		Disconnect();
	}
	else
	{
		Reconnect();
	}
}

void GameSparks::Core::GS_::Reset()
{
	Disconnect();
	m_SessionId = "";
	m_GSPlatform->SetAuthToken("0");
	Reconnect();
}

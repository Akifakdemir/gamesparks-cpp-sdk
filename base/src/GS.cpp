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
    : GameSparksAvailable()
    , GameSparksAuthenticated()
    , m_GSPlatform(NULL)
    , m_RequestCounter(0)
    , m_Ready(false)
    , m_Paused(false)
    , m_Initialized(false)
    , m_durableQueuePaused(false)
    , m_durableQueueRunning(true)
    , m_backOffForSeconds(0.0f)
    , m_SessionId("")
    , OnPersistentQueueLoadedCallback()
{
	/*
		If this assertion fails, your compiler fails to initialize
		GameSparksAvailable, even though a default initialization was
		requested in the initializer list.
	*/
	assert( !GameSparksAvailable );
	assert( !GameSparksAuthenticated );
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

	gSPlatform->DurableInit();
    InitialisePersistentQueue();
    SetDurableQueueRunning(true);
	
#if defined(WINDOWS_PHONE8) || defined(WIN32)
	easywsclient::initEasyWSClient();
#else
	//_gsInitOutcome = true;
#endif

	m_Connections.push_back(new GSConnection(this, m_GSPlatform));
	DebugLog("Initialized");


	/*
	TODO: put into Test
	
	RequestQueue q;
	q.push_back(GSRequest(*this, "fooRequestType"));
	q.push_back(GSRequest(*this, "fooRequestType"));
	q.push_back(GSRequest(*this, "fooRequestType"));
	q.push_back(GSRequest(*this, "fooRequestType"));
	SaveRequestQueue("foo", q);

	RequestQueue q2 = LoadRequestQueue("foo");
	assert(SerializeRequestQueue(q) == SerializeRequestQueue(q2));*/
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

			if (response.ContainsKey("userId"))
			{
				SetUserId(response.GetString("userId").GetValue());
			}
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

void GameSparks::Core::GS_::SendDurable(GSRequest& request)
{
	request.AddString("requestId", GetUniqueRequestId(true));
	m_PersistentQueue.push_front(request);
	WritePersistentQueue();
}

void GameSparks::Core::GS_::Send(GSRequest& request)
{
	if (request.GetDurable())
	{
		SendDurable(request);
		return;
	}

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
		if (!connection->Update(deltaTimeInSeconds))
			break; // websocket error, m_Connections might have changed

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

gsstl::string GameSparks::Core::GS_::GetUniqueRequestId(bool durable)
{
	static char buffer[256];
	snprintf(buffer, sizeof(buffer)/sizeof(buffer[0]), "%ld_%ld", (long)time(0), m_RequestCounter++);
	if (durable)
	{
		return "d_" + gsstl::string(buffer);
	}else
	{
		return gsstl::string(buffer);
	}

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
	ProcessPersistantQueue(deltaTimeInSeconds);
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
				//It's durable request, if it's a ClientError do nothing as it will be retried
                if (request.ContainsKey("@class") && request.GetString("@class").GetValue() != "ClientError")
                {
					RemoveDurableQueueEntry(request);
					
					request.Complete(response);
                }

			}else
			{
				request.Complete(response);
			}
		}
	}

}

bool GameSparks::Core::GS_::RemoveDurableQueueEntry(const GSRequest& request)
{
	gsstl::string idToRemove = request.GetString("requestId").GetValue();
	for (t_PersistentQueue::iterator it = m_PersistentQueue.begin(); it != m_PersistentQueue.end(); it++)
	{
		if (it->GetString("requestId").GetValue() == idToRemove)
		{
			m_PersistentQueue.erase(it);
			WritePersistentQueue();
			m_GSPlatform->DebugMsg("Removed request from persistent queue");

			return true;
		}
	}
	return false;
}

int GameSparks::Core::GS_::GetRequestQueueCount()
{
	return m_PersistentQueue.size();
}

bool GameSparks::Core::GS_::GetDurableQueueRunning()
{
	return m_durableQueueRunning;
}
void GameSparks::Core::GS_::SetDurableQueueRunning(bool value)
{
	m_durableQueueRunning = value;
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
		if (responseType == ".AuthenticationResponse")
		{
			SetUserId(response.GetString("userId").GetValue());
		}
		ProcessReceivedRepsonse(response, connection);
	}
	else if (StringEndsWith(responseType, "Message"))
	{
        t_MessageHandlerMap::iterator pos = m_MessageHandlers.find(responseType);
        
        if (pos != m_MessageHandlers.end()){
            pos->second->CallMessageListener(*this, response);
        }
        //GSMessage::NotifyHandlers(response);
	}
}

void GameSparks::Core::GS_::ProcessPersistantQueue(Seconds deltaTimeInSeconds)
{
	if(!GetDurableQueueRunning() || m_durableQueuePaused)
	{
		return;
	}
	for (t_PersistentQueue::iterator request = m_PersistentQueue.begin(); request != m_PersistentQueue.end(); request++)
	{
		request->SetDurableRetrySeconds(request->GetDurableRetrySeconds() - deltaTimeInSeconds);
		if (request->GetDurableRetrySeconds() <= 0)
		{
			if (m_Connections.size() > 0 && m_Connections[0]->GetReady())
			{
				request->SetWaitForResponseSeconds(request->GetWaitForResponseSeconds());
				request->SetDurableRetrySeconds(10);
				m_Connections[0]->SendImmediate(*request);
			}
		}
	}

}

void GameSparks::Core::GS_::SetUserId(const gsstl::string& userId)
{
	// TODO: Review
	if(m_GSPlatform->GetUserId() != userId)
	{
		m_GSPlatform->SetUserId(userId);
		// clear the pending durable requests for recent user. 
        //Log("New UserId init persistent queue");
		
		//Temporarily stop durable queue processing
		m_durableQueuePaused = true;


		//GSPlatform.ExecuteOnMainThread (() => 
		{
			InitialisePersistentQueue();

			//We want this to be callback to the user code to allow them to make decisions 
			//about the queue before we start processing it, but after it's been initialised
			if (GameSparksAuthenticated)
			{
				GameSparksAuthenticated(*this, userId);
			}
			//Resume queue processing.
			m_durableQueuePaused = false;
		}
	}
    else
	{
		//Log("UserId already known");
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


//! save requests queue as name
void GS_::WritePersistentQueue()
{
	gsstl::string json = SerializeRequestQueue(m_PersistentQueue);
	m_GSPlatform->StoreValue(m_GSPlatform->GetUserId() + "_persistentQueue", json);
}

//! an empty queue will be returned, if no queue named queue can be found
void GS_::InitialisePersistentQueue()
{
	gsstl::string json = m_GSPlatform->LoadValue( m_GSPlatform->GetUserId() + "_persistentQueue");
	m_PersistentQueue = DeserializeRequestQueue(json);
    
    if (OnPersistentQueueLoadedCallback)
    {
        OnPersistentQueueLoadedCallback(*this);
    }
}


gsstl::string GS_::SerializeRequestQueue(const t_PersistentQueue& q)
{
	cJSON* list = cJSON_CreateArray();

	for (t_PersistentQueue::const_iterator i = q.begin(); i != q.end(); ++i)
	{
		cJSON* item = i->GetBaseData();
		cJSON_AddItemReferenceToArray(list, item);
	}

	char* asText = cJSON_Print(list);
	gsstl::string result(asText);
	free(asText);
	cJSON_Delete(list);

	return result;
}


GS_::t_PersistentQueue GS_::DeserializeRequestQueue(const gsstl::string& s)
{
	cJSON* list = cJSON_Parse(s.c_str());

	t_PersistentQueue result;
	if (list)
	{
		int size = cJSON_GetArraySize(list);
		for (int i = 0; i < size; ++i)
		{
			if (cJSON* item = cJSON_GetArrayItem(list, i))
			{
				GSRequest request(*this, item);
				result.push_back(request);
			}
		}

		cJSON_Delete(list);
	}

	return result;
}


GS_::t_PersistentQueue& GS_::GetDurableQueueEntries()
{
	return m_PersistentQueue;
}

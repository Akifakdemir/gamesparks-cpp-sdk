// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GS_h__
#define GS_h__

#pragma once
#include "IGSPlatform.h"
#include "GSRequest.h"
#include "GSConnection.h"
#include <GameSparks/GSLeakDetector.h>
#include <cassert>

#include "./gsstl.h"

//! root GameSparks namespace
namespace GameSparks
{
	//! This namespace contains the hand written gist of the SDK
	namespace Core
	{
		class GSConnection;
		class GSObject;
		class GSRequest;

		/*! The Core GS-API Object.
		  * You can either create an instance of this class locally or create it where ever convenient for you.
		  * Please note, that it is dicouraged to have multiple instances of this class at the same time.
		  */
		class GS_ // this naming should be discussed, it was chosen because we need the static object with the name "GS"
		{
			public:
				#if defined(GS_USE_STD_FUNCTION)
					typedef gsstl::function<void(GS_&, bool)> t_AvailableCallback;
				#else
					typedef void(*t_AvailableCallback)(GS_&, bool);
				#endif /* GS_USE_STD_FUNCTION */

				/// Callback which is triggered whenever the service becomes available or the connection to the service is lost. 
				t_AvailableCallback GameSparksAvailable;

				GS_();

				~GS_();

				/// Initialize this GS_ instance. This has to be called before calling any other member functions.
				void Initialise(IGSPlatform* gSPlatform);

				void printConnections();

				/// shutdown this GS_ instance. You cannot call any other member function after this call.
				void ShutDown();

				/// Stops all connections. 
				void Disconnect();

				/// Reconnect to the GameSparks service. 
				void Reconnect();

				/// Stops all connections, resets the authentication token and establishes a new connection to the service. 
				void Reset();

				/// True if a connection to the service is available for use. 
				bool GetAvailable() const { return m_Ready; }

				/// True if a connection is available and the user is authenticated. 
				bool GetAuthenticated() const;

				/// <summary>
				/// Send the given request durable. 
				/// Durable requests are persisted automatically. 
				/// If it cannot be send right now the sdk will try to send it later. 
				/// </summary>
				//void SendDurable(GSRequest& request);

				/// Send the given request. 
				void Send(GSRequest& request);

				// True if a connection to the service is available for use. 
				// bool GetGameSparksAvailable();

				/// Update this GS_-instance. This has to be called as often as possible
				/// @param deltaTimeInSeconds the time since the last call to Update() in seconds
				void Update(Seconds deltaTimeInSeconds);

	            /*!
	                Registers MessageListener via GS.SetMessageListener(OnAchievementEarnedMessage)
	                if you pass null, the MessageListener is unregistered.

	                Note: the signature could also be written as:
	                void SetMessageListener(const typename MessageType::t_ListenerFunction& listener)
	             
	                but writing out the type (e.g. not using a dependent type name) enabled the compiler to
	                deduce MessageType. So the user can write:
	                    GS.SetMessageListener(OnAchievementEarnedMessage)
	                instead of
	                    GS.SetMessageListener<GameSparks::Api::Messages::AchievementEarnedMessage>(OnAchievementEarnedMessage);
	             
	                This of cause only works, if the passed MessageListener has the correct Signature:
	                    
	                void OnAchievementEarnedMessage(GameSparks::Core::GS_& gsInstance, const MessageType& message)

	                @tparam MessageType the type of the message you want to listen for
	             */
	            template <typename MessageType>
	            #if defined(GS_USE_STD_FUNCTION)
	                void SetMessageListener(const gsstl::function<void(class GS_&, const MessageType&)>& listener)
	            #else
	                void SetMessageListener( void(*listener)(class GS_&, const MessageType&) )
	            #endif /* GS_USE_STD_FUNCTION */
	            {
	                const char* messageTypeName = MessageType::GetTypeName();
	                t_MessageHandlerMap::iterator pos = m_MessageHandlers.find(messageTypeName);
	                
	                if (pos != m_MessageHandlers.end())
	                    delete pos->second;

	                if (listener)
	                {
	                    m_MessageHandlers[ MessageType::GetTypeName() ] = new MessageListener<MessageType>(listener);
	                }
	            }

	            /*/// returns the Device-Id provided by IGSPlatform instance this GS-instance was initialized with.
	            gsstl::string GetDeviceId() const
	            {
	            	// you have to call Initialize with a non-null platform instance first
	            	assert(m_GSPlatform);
	            	return m_GSPlatform->GetDeviceId();
	            }

	            /// returns the Device-OS provided by IGSPlatform instance this GS-instance was initialized with.
	            gsstl::string GetDeviceOS() const
	            {
	            	// you have to call Initialize with a non-null platform instance first
	            	assert(m_GSPlatform);
	            	return m_GSPlatform->GetDeviceOS();
	            }*/
			private:
				friend class GSConnection;
				void OnWebSocketClientError(const gsstl::string& errorMessage, GSConnection* connection);
				void OnMessageReceived(const gsstl::string& message, GSConnection& connection);
				gsstl::string GetServiceUrl() const { return m_ServiceUrl; }
				void SetAvailability(bool available);
				Seconds GetRequestTimeoutSeconds();

				void DebugLog(const gsstl::string& message);

				void NetworkChange(bool available);
				void UpdateConnections(Seconds deltaTimeInSeconds);
				void Stop(bool termiante);
				void NewConnection();
				void Handshake(GSObject& response, GSConnection& connection);
				void SendHandshake(GSObject& response, GSConnection& connection);
				gsstl::string GetUniqueRequestId();
				void ConnectIfRequired();
				void ProcessSendQueue(Seconds deltaTimeInSeconds);
				void CancelRequest(GSRequest& request);
				void CancelRequest(GSRequest& request, GSConnection* connection);
				void ProcessQueues(Seconds deltaTimeInSeconds);
				void TrimOldConnections();
				void ProcessReceivedRepsonse(const GSObject& response, GSConnection* connection);
				void ProcessReceivedItem(const GSObject& response, GSConnection* connection);

				IGSPlatform* m_GSPlatform;
				typedef gsstl::vector<GSConnection*> t_ConnectionContainer;
				t_ConnectionContainer m_Connections;
				gsstl::string m_ServiceUrl;

				typedef gsstl::list<GSRequest> t_SendQueue;
				t_SendQueue m_SendQueue;

				long m_RequestCounter;

				// BS: we might want to change this to a state enum. they appear to be mutually exclusive.
				bool m_Ready;
				bool m_Paused;
				bool m_Initialized;
				Seconds m_backOffForSeconds;
				gsstl::string m_SessionId;

	            /*
	                MessageListeners
	             */
	            
	            // base class - provides the interface
	            struct MessageListenerBase
	            {
	                virtual void CallMessageListener(GS_& gsInstance, const GSData& message) const = 0;
	                virtual ~MessageListenerBase(){}
	                
	                private:
	                GS_LEAK_DETECTOR(MessageListenerBase);
	            };
	            
	            // specialisation for a concrete MessageType
	            template <typename MessageType>
	            struct MessageListener : public MessageListenerBase
	            {
	                #if defined(GS_USE_STD_FUNCTION)
	                    typedef gsstl::function<void(class GS_&, const MessageType&)> t_ListenerFunction;
	                #else
	                    typedef void(*t_ListenerFunction)(class GS_&, const MessageType&);
	                #endif /* GS_USE_STD_FUNCTION */

	                MessageListener(const t_ListenerFunction& listener)
	                :m_Listener(listener) {}

	                virtual void CallMessageListener(GS_& gsInstance, const GSData& data) const
	                {
	                    MessageType message(data); // convert yelly bean GSData to concrete GSMessage
	                    m_Listener(gsInstance, message); // call the listener
	                }
	                
	                t_ListenerFunction m_Listener;
	                
	                GS_LEAK_DETECTOR(MessageListener);
	            };
	            
	            typedef gsstl::map<gsstl::string, MessageListenerBase*> t_MessageHandlerMap;
	            t_MessageHandlerMap m_MessageHandlers;
	            
	            private:
	            GS_LEAK_DETECTOR(GS_);
		};
	} /* namespace Core */

	/// \example sample01_connect.cpp This is an example of how to use the GS_ class.
	/// \example sample02_connect_static.cpp This is an example of how to use GameSparks via a global GS_-objects.
	/// \example sample03_authentication.cpp This is an example of how to authenticate a user.
	/// \example sample05_challangerequest.cpp This is an example on how to use CreateChallengeRequest.
	/// \example sample04_listachievements.cpp This is an example of how to list some achievements.

	/// \example sample06_stresstest.cpp This is more a test than an example. It shows, that the teardown and assignment works cleanly.

	// this block is here for doxygen
	//! This namespace contains the auto-generated classes related to the built-in GameSparks API. 
	//! For more information on the toppic visit https://docs.gamesparks.net/documentation/
	namespace Api
	{
		//! built-in Messages. For more information visit https://docs.gamesparks.net/documentation/gamesparks-message-api
		namespace Messages {}
		
		//! built-in Requests. For more information visit https://docs.gamesparks.net/documentation/gamesparks-service-request-api
		namespace Requests {}

		//! built-in Responses. For more information visit https://docs.gamesparks.net/uncategorized/gamesparks-service-response-api
		namespace Responses {}

		//! Types used commonly by the built-in Requests, Responses and Messages
		namespace Types {}
	}
}
#endif // GS_h__

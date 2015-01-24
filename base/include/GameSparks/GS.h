// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GS_h__
#define GS_h__

#pragma once
#include "IGSPlatform.h"
#include "GSRequest.h"
#include "GSConnection.h"
#include <GameSparks/GSLeakDetector.h>

#include "./gsstl.h"

namespace GameSparks
{
	namespace Core
	{
		class GSConnection;
		class GSObject;
		class GSRequest;

		class GS_ // this naming should be discussed, it was chosen because we need the static object with the name "GS"
		{
		public:
			#if defined(GS_USE_STD_FUNCTION)
				typedef gsstl::function<void(GS_&, bool)> t_AvailableCallback;
			#else
				typedef void(*t_AvailableCallback)(GS_&, bool);
			#endif /* GS_USE_STD_FUNCTION */

			t_AvailableCallback GameSparksAvailable;

			GS_();

			~GS_();

			void Initialise(IGSPlatform* gSPlatform);

			void printConnections();

			void ShutDown();

			void Disconnect();

			void Reconnect();

			void Reset();

			void NetworkChange(bool available);

			bool GetAvailable() const { return m_Ready; }

			bool GetAuthenticated() const;

			void SendDurable(GSRequest& request);

			void Send(GSRequest& request);

			int GetRequestTimeoutSeconds();

			bool GetGameSparksAvailable();

			void Update(float deltaTime);
			
			void OnWebSocketClientError(const gsstl::string& errorMessage, GSConnection* connection);
			void OnMessageReceived(const gsstl::string& message, GSConnection& connection);
			gsstl::string GetServiceUrl() const { return m_ServiceUrl; }
			void SetAvailability(bool available);

			void DebugLog(const gsstl::string& message);
            
            /*
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
		private:
			void UpdateConnections(float deltaTime);
			void Stop(bool termiante);
			void NewConnection();
			void Handshake(GSObject& response, GSConnection& connection);
			void SendHandshake(GSObject& response, GSConnection& connection);
			gsstl::string GetUniqueRequestId();
			void ConnectIfRequired();
			void ProcessSendQueue(float deltaTime);
			void CancelRequest(GSRequest& request);
			void CancelRequest(GSRequest& request, GSConnection* connection);
			void ProcessQueues(float deltaTime);
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
			bool m_Ready;
			bool m_Error;
			bool m_Paused;
			bool m_Initialized;
			gsstl::string m_SessionId;

			friend class GSConnection;
            
            /*
                MessageListeners
             */
            
            // base class - provides the interface
            struct MessageListenerBase
            {
                virtual void CallMessageListener(GS_& gsInstance, const GSData& message) const = 0;
                virtual ~MessageListenerBase(){}
                
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
            
            GS_LEAK_DETECTOR(GS_);
		};
	}
}
#endif // GS_h__

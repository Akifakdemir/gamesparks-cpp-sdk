#pragma once
#include "IGSPlatform.h"
#include "GSRequest.h"
#include "GSConnection.h"

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
				typedef gsstl::function<void(bool)> t_AvailableCallback;
			#else
				typedef void(*t_AvailableCallback)(bool);
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
		};

		extern /*__declspec(dllimport)*/ GS_ GS;
	}
}

#pragma once

#include "GS.h"
#include "IGSPlatform.h"
#include "GSRequest.h"

namespace easywsclient 
{
	class WebSocket;
}

namespace GameSparks
{
	namespace Core
	{
		class GS_;
		class GSRequest;

		class GSConnection
		{
		public:
			GSConnection(GS_* gs, IGSPlatform* gsPlatform);
			~GSConnection();

			void Terminate();
			void Stop();
			void Close();
			void OnOpened();
			void OnClosed();
			void OnError(const gsstl::string& errorMessage);
			void EnsureConnected();
			bool GetReady() const;
			void SetReady(bool ready);
			void SendImmediate(GSRequest& request);

			void Update(float deltaTime);
			 GS_* GetGSInstance() const { return m_GS; }
			 bool IsWebSocketConnectionAlive() const;
		protected:
			static void OnWebSocketCallback(const gsstl::string& message, void* userData);
		private:
			GS_* m_GS;
			IGSPlatform* m_GSPlatform;

			easywsclient::WebSocket* m_WebSocket;
			gsstl::string m_URL;
			bool m_Initialized;
			bool m_Stopped;

			typedef gsstl::map<gsstl::string, GSRequest> t_RequestMap;
			typedef gsstl::pair<gsstl::string, GSRequest> t_RequestMapPair;
			t_RequestMap m_PendingRequests;

			friend class GS_;
		};
	}
}
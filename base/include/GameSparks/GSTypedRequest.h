#pragma once

#include "GSRequest.h"
#include "GSTypedResponse.h"
#include <cassert>

namespace GameSparks
{
	namespace Core
	{
		template<typename RequestType, typename ResponseType>
		class GSTypedRequest 
		{
		public:

			#if defined(GS_USE_STD_FUNCTION)
				typedef gsstl::function<void(const ResponseType&)> t_ResponseCallback;
			#else
				typedef void(*t_ResponseCallback)(const ResponseType&);
			#endif /* GS_USE_STD_FUNCTION */

			GSRequest m_Request;

			GSTypedRequest()
				: m_Request(".LogEventRequest")
			{

			}

			GSTypedRequest(const gsstl::string& type)
				: m_Request(type)
			{
			}

			/*
			GSTypedRequest(const GSTypedRequest<RequestType, ResponseType>& other)
				: m_Request(other.m_Request)
			{

			}*/

			//GSTypedRequest(cJSON*);

			void AddCompleter(GSRequest::t_Callback completer);

			virtual ResponseType BuildRepsonse(const GSObject& response)
			{
				return ResponseType(response);
			}

			virtual gsstl::string GetJSONString() const
			{
				return m_Request.GetJSON();
			}

			virtual cJSON* GetJSONData() const
			{
				return m_Request.GetBaseData();
			}

			virtual RequestType& SetDurable(bool durable)
			{
				return static_cast<RequestType&>(*this);
			}

			virtual RequestType& SetScriptData(const GSRequestData& data)
			{
				m_Request.AddObject("scriptData", data);
				return static_cast<RequestType&>(*this);
			}

			virtual ResponseType Send()
			{
				return m_Request.Send();
			}

			virtual void Send(t_ResponseCallback callback, int timeoutSeconds=-1)
			{
				m_Request.Send(new Callbacks(callback, callback), timeoutSeconds);
			}

			virtual void Send(t_ResponseCallback successCallback, t_ResponseCallback errorCallback, int timeoutSeconds=-1)
			{
				m_Request.Send(new Callbacks(successCallback, errorCallback), timeoutSeconds);
			}

			class Callbacks : public GSRequest::BaseCallbacks
			{
				public:
					Callbacks(t_ResponseCallback onSuccess, t_ResponseCallback onError = t_ResponseCallback())
					:m_onSuccess(onSuccess), m_onError(onError) {}

					virtual void OnSucess(const GSObject& response)
					{
						if ( m_onSuccess ) m_onSuccess( response );
					}

					virtual void OnError (const GSObject& response)
					{
						if ( m_onError ) m_onError( response );			
					}

					virtual Callbacks* Clone() const
					{
						return new Callbacks( m_onSuccess, m_onError );
					}
				private:
					t_ResponseCallback m_onSuccess;
					t_ResponseCallback m_onError;
			};
		};
	}
}
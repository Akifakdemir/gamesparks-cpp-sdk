// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSTypedRequest_h__
#define GSTypedRequest_h__

#pragma once

#include "GSRequest.h"
#include "GSTypedResponse.h"
#include <GameSparks/GSLeakDetector.h>
#include <cassert>

namespace GameSparks
{
	namespace Core
	{
		template<typename RequestType, typename ResponseType>
		class GSTypedRequest 
		{
            GS_LEAK_DETECTOR(GSTypedRequest);
            
		public:

			#if defined(GS_USE_STD_FUNCTION)
				typedef gsstl::function<void(GS_&, const ResponseType&)> t_ResponseCallback;
			#else
				typedef void(*t_ResponseCallback)(GS_&, const ResponseType&);
			#endif /* GS_USE_STD_FUNCTION */

			GSRequest m_Request;

			GSTypedRequest(GS_& gsInstance)
				: m_Request(gsInstance, ".LogEventRequest")
			{

			}

			GSTypedRequest(GS_& gsInstance, const gsstl::string& type)
				: m_Request(gsInstance, type)
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

					virtual void OnSucess(GS_& gsInstance, const GSObject& response)
					{
						if ( m_onSuccess ) m_onSuccess( gsInstance, response );
					}

					virtual void OnError (GS_& gsInstance, const GSObject& response)
					{
						if ( m_onError ) m_onError( gsInstance, response );
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
#endif // GSTypedRequest_h__
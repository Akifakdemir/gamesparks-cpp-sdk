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
		/*!
			Wraps a GSRequest but can be parameterized by the concrete RequestType and ResponseType.
			This is the base class for all built-in Requests.

			@tparam RequestType the concrete type of the request
			@tparam ResponseType the concrete type of the response
		*/
		template<typename RequestType, typename ResponseType>
		class GSTypedRequest 
		{
            GS_LEAK_DETECTOR(GSTypedRequest);

			public:

				#if defined(GS_USE_STD_FUNCTION)
					/// the response callback as a std::function, in case all the compilers you need to support have support for C++11.
					/// this also supports C++11 lambdas
					typedef gsstl::function<void(GS_&, const ResponseType&)> t_ResponseCallback;
				#else
					/// response callback as a c-style function pointer.
					/// In case you need to support ancient compilers.
					typedef void(*t_ResponseCallback)(GS_&, const ResponseType&);
				#endif /* GS_USE_STD_FUNCTION */

				/// the wrapped request
				GSRequest m_Request;

				/// constructor.
				GSTypedRequest(GS_& gsInstance)
					: m_Request(gsInstance, ".LogEventRequest")
				{

				}

				/// constructor with request type
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

				// void AddCompleter(GSRequest::t_Callback completer);


				/* TODO: check if this is needed and if this works
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
					m_Request.SetDurable(durable);
					return static_cast<RequestType&>(*this);
				}

				virtual RequestType& SetScriptData(const GSRequestData& data)
				{
					m_Request.AddObject("scriptData", data);
					return static_cast<RequestType&>(*this);
				}*/

				/// send this request to the server
				virtual ResponseType Send()
				{
					return m_Request.Send();
				}

				// TODO: check if the type cound be changed to Seconds
				/// send this request with a response-callback and optional timeout (in seconds)
				/// callback will be called in case of success and error. you have to examine the passed response
				/// to find out if the request failed.
				/// TODO: 
				virtual void Send(t_ResponseCallback callback, int timeoutSeconds=-1)
				{
					m_Request.Send(new Callbacks(callback, callback), timeoutSeconds);
				}

				// TODO: check if the type cound be changed to Seconds
				/// send this request with a successCallback, errorCallback and optional timeout (in seconds)
				virtual void Send(t_ResponseCallback successCallback, t_ResponseCallback errorCallback, int timeoutSeconds=-1)
				{
					m_Request.Send(new Callbacks(successCallback, errorCallback), timeoutSeconds);
				}

				private:
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
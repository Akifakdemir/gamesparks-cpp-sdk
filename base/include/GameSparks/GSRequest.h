// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSRequest_h__
#define GSRequest_h__

#pragma once

#include "GSObject.h"
#include "./gsstl.h"
#include "GSDateTime.h"

namespace GameSparks
{
	namespace Core
	{
		class GS_;

		class GSRequest : public GSObject
		{
			public:
				#if defined(GS_USE_STD_FUNCTION)
					typedef gsstl::function<void (const GSObject&)> t_Callback;
				#else
					typedef void(*t_Callback)(const GSObject&);
				#endif /* GS_USE_STD_FUNCTION */

				GSRequest(GS_& gsInstance, const gsstl::string& requestType);
				GSRequest(GS_& gsInstance, cJSON* data);
				//GSRequest(const GSRequest& other);

				virtual GSRequestData& AddString(const gsstl::string& paramName, const gsstl::string& value);
				virtual GSRequestData& AddDate(const gsstl::string& paramName, const GSDateTime& date);
				virtual GSRequestData& AddNumber(const gsstl::string& paramName, long value);
				virtual GSRequestData& AddObject(const gsstl::string& paramName, const GSData& child);
				virtual GSRequestData& AddObjectList(const gsstl::string& paramName, const gsstl::vector<GSData>& child);
				virtual GSRequestData& AddStringList(const gsstl::string& paramName, const gsstl::vector<gsstl::string>& child);
				virtual GSRequestData& AddBoolean(const gsstl::string& paramName, bool value);

				bool GetDurable() const { return m_Durable; }
				void SetDurable(bool durable) { m_Durable = durable; }

				long GetCancelTicks() const { return m_CancelTicks; }
				void SetCancelTicks(long cancelTicks) { m_CancelTicks = cancelTicks; }

				long GetWaitForResponseTicks() const { return m_WaitForResponseTicks; }
				void SetWaitForResponseTicks(long waitForRepsonseTicks) { m_WaitForResponseTicks = waitForRepsonseTicks; }
			
				long GetDurableRetryTicks() const { return m_DurableRetryTicks; }
				void SetDurableRetryTicks(long durableRetryTicks) { m_DurableRetryTicks = durableRetryTicks; }
		
			private:
				GS_& GetGSInstance() const { return m_GSInstance; }

				void Complete(const GSObject& response);			

				GSObject m_Response;

				GS_& m_GSInstance;

				t_Callback m_Completer;

				bool m_Durable;
				long m_CancelTicks;
				long m_WaitForResponseTicks;
				long m_DurableRetryTicks;

				/*
					This class is here so that it can be implemented in GSTypedRequest.
					We need to hold a pointer to the base class, because the concrete
					implementations hold templated (specialized) function pointers.

					This whole construct is needed, because we cannot depend on stl-function
					We need to support raw function pointers as well.
				*/
				struct BaseCallbacks
				{
					virtual ~BaseCallbacks() {}
					virtual void OnSucess(GS_& gsInstance, const GSObject& response) = 0;
					virtual void OnError (GS_& gsInstance, const GSObject& response) = 0;
					virtual BaseCallbacks* Clone() const = 0;
                    GS_LEAK_DETECTOR(BaseCallbacks)
				};

				/* iff all the members behave the way one would expect them to,
					the auto-generated copy-constructors and assignment operators
					behave as one would expect them to. By implementing this thin
					pointer wrapper, we spare us the burden of maintaining the CCs
					and AOs of GSRequest.
				*/
				class BaseCallbacksPtr
				{
					public:
						// constructor						
						BaseCallbacksPtr(BaseCallbacks* callbacks=0)
						: ptr(callbacks) {}

						// destructor
						virtual ~BaseCallbacksPtr()
						{
							delete ptr;
						}

						// copy constructor (this is the interesting part)
						BaseCallbacksPtr(const BaseCallbacksPtr& other)
						: ptr( other.ptr ? other.ptr->Clone() : 0) {}

						// assignment operator
						BaseCallbacksPtr& operator=(BaseCallbacksPtr other)
						{
							swap(*this, other); // copy and swap idom
							return *this;
						}

						// pointer access operator
						BaseCallbacks* operator-> ()
						{
							return ptr;
						}

						// conversion to bool (e.g. wrapped pointer not null)
						operator bool () const
						{
							return ptr != 0;
						}
					private:
						static void swap(BaseCallbacksPtr& first, BaseCallbacksPtr& second)
						{
							// We'd prefer to use stl-swap, but cannot depend on having the stl.
							BaseCallbacks* tmp = first.ptr;
							first.ptr = second.ptr;
							second.ptr = tmp;
						}

						BaseCallbacks* ptr;
                    
                        GS_LEAK_DETECTOR(BaseCallbacksPtr);
				};

				void Send(BaseCallbacks* callbacks, int timeoutSeconds);
				GSObject Send();

				//BaseCallbacks* m_callbacks;
				BaseCallbacksPtr m_callbacks;

				template<typename RequestType, typename ResponseType>
				friend class GSTypedRequest;
	
				friend class GS_;
            
                GS_LEAK_DETECTOR(GSRequest);
		};
	}
}
#endif // GSRequest_h__
// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSOptional_h__
#define GSOptional_h__

#pragma once

#include "./gsstl.h"
#include <GameSparks/GSLeakDetector.h>

namespace GameSparks
{
	//! namespace for optional types
	//! This is roughly equivalent to C-Sharps Nullable or boost::optional
	namespace Optional
	{
		/*!
		 *  Template class for optional values.
		 * @tparam ValueType the wrapped data type		 
		 */

		template<typename ValueType>
		class Optional_
		{
			public:
				//! construct an empty Optional_
				Optional_()
	                : m_Value(ValueType())
	                , m_HasValue(false)
				{

				}

				//! construct an Optional_ from a given value
				Optional_(const ValueType& value)
					: m_Value(value)
	                , m_HasValue(true)
				{

				}

				/// construct an optional from value and hasValue
				Optional_(const ValueType& value, bool hasValue)
					: m_Value(value)
	                , m_HasValue(hasValue)
				{

				}

				/// copy constructor
				Optional_(const Optional_& other)
					: m_Value(other.m_Value)
	                , m_HasValue(other.m_HasValue)
				{

				}

				//! compare two Optional_<T>. No implicity type conversion will be performed.
				//! Two Optional_ are equal, if the wrapped value is equal AND both are set.
				Optional_& operator=(const Optional_& other)
				{
					if (&other != this)
					{
						m_HasValue = other.m_HasValue;
						m_Value = other.m_Value;
					}
					return *this;
				}

				//! return the wrapped value. You have to check HasValue before doing this, otherwise the default constructed wrapped type will be returned.
				ValueType& GetValue()
				{
					return m_Value;
				}

				//! checks wether a value has been set or not
				bool HasValue() const
				{
					return m_HasValue;
				}

			private:
				ValueType m_Value;
				bool m_HasValue;
	            
	            GS_LEAK_DETECTOR(Optional_);
		};

		/// an optional string
		typedef Optional_<gsstl::string> t_StringOptional;
		/// an optional int
		typedef Optional_<int> t_IntOptional;
		/// an optional long
		typedef Optional_<long> t_LongOptional;
		/// an optional float
		typedef Optional_<float> t_FloatOptional;
		/// an optional double
		typedef Optional_<double> t_DoubleOptional;
		/// an optional bool
		typedef Optional_<bool> t_BoolOptional;
	}

}
#endif // GSOptional_h__
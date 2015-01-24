// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSOptional_h__
#define GSOptional_h__

#pragma once

#include "./gsstl.h"
#include <GameSparks/GSLeakDetector.h>

namespace GameSparks
{
	namespace Optional
	{
		template<typename ValueType>
		class Optional_
		{
		public:
			Optional_()
                : m_Value(ValueType())
                , m_HasValue(false)
			{

			}

			Optional_(const ValueType& value)
				: m_Value(value)
                , m_HasValue(true)
			{

			}

			Optional_(const ValueType& value, bool hasValue)
				: m_Value(value)
                , m_HasValue(hasValue)
			{

			}

			Optional_(const Optional_& other)
				: m_Value(other.m_Value)
                , m_HasValue(other.m_HasValue)
			{

			}

			Optional_& operator=(const Optional_& other)
			{
				if (&other != this)
				{
					m_HasValue = other.m_HasValue;
					m_Value = other.m_Value;
				}
				return *this;
			}

			ValueType& GetValue()
			{
				return m_Value;
			}

			bool HasValue() const
			{
				return m_HasValue;
			}

		private:
			ValueType m_Value;
			bool m_HasValue;
            
            GS_LEAK_DETECTOR(Optional_);
		};

		typedef Optional_<gsstl::string> t_StringOptional;
		typedef Optional_<int> t_IntOptional;
		typedef Optional_<long> t_LongOptional;
		typedef Optional_<float> t_FloatOptional;
		typedef Optional_<double> t_DoubleOptional;
		typedef Optional_<bool> t_BoolOptional;
	}

}
#endif // GSOptional_h__
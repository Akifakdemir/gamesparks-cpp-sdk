#pragma once

#include <GameSparks/gsstl.h>
#include <GameSparks/GSOptional.h>

namespace GameSparks
{
	namespace Core
	{
		class GSDateTime
		{
		public:
			typedef GameSparks::Optional::Optional_<GSDateTime> t_Optional;

			GSDateTime();
			GSDateTime(int day, int month, int year, int hour, int minute, int second, bool isLocalTime);
			GSDateTime(time_t time, bool isLocalTime);
			GSDateTime(const gsstl::string& iso8601_str);
			GSDateTime(const GSDateTime& other);
			GSDateTime& operator=(const GSDateTime& other);
			static GSDateTime Now();

			GSDateTime ToLocalTime() const;
			GSDateTime ToGMTime() const;
			// Returns the DateTime object as a ISO 8601 string (eg. '2011-10-08T07:07:09Z') representation
			gsstl::string ToString() const;

			int GetDay() const;
			int GetMonth() const;
			int GetYear() const;
			int GetHour() const;
			int GetMinute() const;
			int GetSecond() const;
			bool IsLocalTime() const;

			GSDateTime AddSeconds(int seconds);
			GSDateTime AddMinutes(int minutes);
			GSDateTime AddHours(int hours);
			GSDateTime AddDays(int days);
			GSDateTime AddMonths(int months);
			GSDateTime AddYears(int years);

		private:
			time_t m_time;
			bool m_IsLocalTime;
		};
	}
}
#pragma once

namespace lic {

	/* Struct representing time for reservations.
	*/
	class Time {
	public:
		/* Only hours and minutes are represented.
		*/
		int _hour, _minute;
		Time()
			: _hour(0), _minute(0) {}
		Time(int hour, int minute)
			: _hour(hour), _minute(minute) {}
		/* Comparison operator
		*/
		bool operator==(const Time& other) const {
			return other._hour == _hour && other._minute == _minute;
		}
	};

}
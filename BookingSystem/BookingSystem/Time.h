#pragma once

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
		: _hour(hour), _minute(_minute) {}
};
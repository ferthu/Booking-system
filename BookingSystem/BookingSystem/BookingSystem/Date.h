#pragma once

namespace lic {

	/* Struct representing a date in the system.
	*/
	class Date {
	public:
		/* Only hours and minutes are represented.
		*/
		int _year, _month, _day;
		
		Date()
		: _year(0), _month(0), _day(0){}
		Date(int year, int month, int day)
			: _year(year), _month(month), _day(day){}
		/* Comparison operator
		*/
		bool operator==(const Date& other) const {
			return other._year == _year && other._month == _month && other._day == _day;
		}
	};
}
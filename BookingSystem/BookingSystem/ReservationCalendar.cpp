/* Created by: Mattias Fredriksson
*/
#include "ReservationCalendar.h"


namespace lic {

	ReservationCalendar::ReservationCalendar()
	{
	}


	ReservationCalendar::~ReservationCalendar()
	{
	}


	/* Fetches a set of available time slots from a reservation setting and a date
	*/
	std::vector<Time>& ReservationCalendar::freeReservations(const Reservation& res, const Date date) {
		std::vector<Time> free;

		return free;
	}
	/* Reserve the time slot specified for the date, the reservations date/time parameters will be updated.
	*/
	bool ReservationCalendar::reserve(Reservation& res, const Date date, const Time time) {

		if (false)
			return false;

		res._date = date;
		res._time = time;
		return true;
	}
	/*	Finalizes the reservation. Confirming the reservation date & time reserved.
	The reservation will be bound to the specified account.
	*/
	void ReservationCalendar::finalize(const Reservation& res, IAccount& account) {
		Reservation found;
		found._accountName = account.getName();
	}
	/* Deletes a reserved reservation in the calendar.
	*/
	void ReservationCalendar::editReservation(const Reservation& res) {

	}
	/* Fetches the reservations reserved by the specified account.
	*/
	std::vector<Reservation>& ReservationCalendar::getReservations(const std::string& accountName) {

	}

}
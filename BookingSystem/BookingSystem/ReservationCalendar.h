/* Created by: Mattias Fredriksson
*/
#pragma once

#include "IReservationCalendar.h"


namespace lic {

	/* Calendar implementation.
	*/
	class ReservationCalendar :
		public IReservationCalendar
	{
	public:
		ReservationCalendar();
		virtual ~ReservationCalendar();


		/* Fetches a set of available time slots from a reservation setting and a date
		*/
		virtual std::vector<Time>& freeReservations(const Reservation& res, const Date date);
		/* Reserve the time slot specified for the date, the reservations date/time parameters will be updated.
		*/
		virtual bool reserve(Reservation& res, const Date date, const Time time);
		/*	Finalizes the reservation. Confirming the reservation date & time reserved.
		The reservation will be bound to the specified account
		*/
		virtual void finalize(const Reservation& res, IAccount& account);
		/* Deletes a reserved reservation in the calendar.
		*/
		virtual void editReservation(const Reservation& res);
		/* Fetches the reservations reserved by the specified account.
		*/
		virtual std::vector<Reservation>& getReservations(const std::string& accountName);
	};

}


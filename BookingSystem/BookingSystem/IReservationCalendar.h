#pragma once



#include"Reservation.h"
#include"IAccount.h"
#include<vector>

namespace lic {

	/*	Calendar keeping track of reservations for the system.
		Can be quiried for available time slots and for reserving available slots.
	*/
	class IReservationCalendar
	{
	public:
		virtual ~IReservationCalendar() {};

		/* Fetches a set of available time slots from a reservation setting and a date
		*/
		virtual std::vector<Time>& freeReservations(const Reservation& res, const Date date) = 0;
		/* Reserve the time slot specified for the date, the reservations date/time parameters will be updated.
		*/
		virtual bool reserve(Reservation& res, const Date date, const Time time) = 0;
		/*	Finalizes the reservation. Confirming the reservation date & time reserved. 
			The reservation will be bound to the specified account
		*/
		virtual void finalize(const Reservation& res, IAccount& account) = 0;
		/* Deletes a reserved reservation in the calendar.
		*/
		virtual void editReservation(const Reservation& res) = 0;
	};
}
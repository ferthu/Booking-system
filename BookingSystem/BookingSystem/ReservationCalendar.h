/* Created by: Mattias Fredriksson
*/
#pragma once

#include "IReservationCalendar.h"
#include"Reservation.h"


namespace lic {
	/* Calendar days count:
	*/
	static const int DAYPERMONTH[12] = { 31, 28, 31, 30,31,30,31,31,30,31,30,31 };
	static const int DAYPERYEAR = 365;
	/* Number of time slots per day:
	*/
	static const int SLOTSPERHOUR = 1;
	static const int MINPERSLOT = 60 / SLOTSPERHOUR;
	static const int SLOTPERDAY = SLOTSPERHOUR * 24; //Slots per hour and open 24/7
	/* Number of services that can be reserved at the same time:
	*/
	static const int SERVICECOUNT = 5;

	/* Calendar implementation.
	*/
	class ReservationCalendar :
		public IReservationCalendar
	{
	private:
		/* Current date
		*/
		Date _date;

		/* Time slots linked to the reservations. Holds 
		*/
		std::vector<std::vector<std::vector<int>>> _timeslots;
		/* Reservations reserved in the system. Holds a set of reservations for each day.
		*/
		std::vector<std::vector<Reservation>> _reservations;
		/* Calculates a index for the reservation arrays from a specified date.
		*/
		int dateToIndex(const Date& d);
		/* Converts time to a slot index
		*/
		int timeToSlotIndex(const Time t);
		/* Converts a slot index to time
		*/
		Time slotIndexToTime(int slotIndex);

		/* Sort availability for a specified service from a available time slots. 
		Given a set of reservations and number of players.
		*/
		void sortAvailable(const std::string& serviceName, int playerCount, int dateIndex, std::vector<Time>& available);
		/* Return if a specific slot is available
		*/
		bool slotAvailable(const std::string& serviceName, int maxReservationCount, int dateIndex, int slotIndex, int playerCount);

		/* Finds a reference for a reservation in the calendar equal to the specified reservation data.
		*/
		int findReservation(const Reservation& res, Reservation* ref);
	public:
		ReservationCalendar(const Date d);
		virtual ~ReservationCalendar();

		/* Access calendar date
		*/
		Date getDate();


		/* Fetches a set of available time slots from a reservation setting and a date
		*/
		virtual std::shared_ptr<std::vector<Time>> freeReservations(const Reservation& res, const Date date);
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


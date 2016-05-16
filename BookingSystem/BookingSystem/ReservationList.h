/* Mattias
*/
#pragma once

#include"Reservation.h"

namespace lic {

	/* Struct holding a time and a set of reservations. Used to return the reservations for a time slot.
	*/
	struct ReservationList {
		/* The reservation time slot
		*/
		Time _time;
		/* Reservations for the specific slot
		*/
		std::vector<Reservation> _list;

		ReservationList() {}
		ReservationList(Time time)
		 : _time(time), _list(){}
		ReservationList(Time time, const std::vector<Reservation>& list)
			: _time(time), _list(list) {}
	};

}
#pragma once

#include"ReservationCalendar.h"
#include"ISystem.h"

namespace lic {

	/* The system object implementation. Access point and container for the logic layer functions/objects.
	*/
	class System : public ISystem
	{
		/* Private objects: ReservationCalendar, Libraries
		*/
	private:

		/* The system reservation calendar, holding all reservations */
		ReservationCalendar _calendar;

		/* Public access functions.
		*/
	public:
		System();
		~System();


		/* Access the reservation calendar
		*/
		IReservationCalendar& getCalendar();
	};

}

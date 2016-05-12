#pragma once

#include"IReservationCalendar.h"

namespace lic {

	/* System interface accessible from the UI layer
	*/
	class ISystem {
	public:

		/*
		Todo: Add UI access functions 
		*/

		/* Access the reservation calendar
		*/
		virtual IReservationCalendar& getCalendar() = 0;

		virtual ~ISystem() {};
	};

}
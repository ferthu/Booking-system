#include "System.h"

namespace lic {

	System::System()
	{
	}


	System::~System()
	{
	}


	/* Access the reservation calendar
	*/
	IReservationCalendar& System::getCalendar() {
		return _calendar;
	}

}
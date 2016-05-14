#pragma once

#include"IReservationCalendar.h"
#include"ILibrary.h"
#include"SystemServices.h"
#include"SystemLibraries.h"

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

		/* Access the current date
		*/
		virtual Date getDate() = 0;

		/* Access a library from the system
		*/
		virtual ILibrary& getLibrary(const std::string& library) = 0;

		virtual ~ISystem() {};
	};

}
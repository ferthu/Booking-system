#pragma once

#include"ReservationCalendar.h"
#include"ISystem.h"
#include "Account.h"

#include <vector>

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

		/* Vector holding user accounts */
		std::vector<Account> accounts;

		/* Reference to currently logged in account */
		lic::Account* signedInAs;

		/* Public access functions.
		*/
	public:
		bool login(std::string username, std::string password);
		void addAccount(lic::Account newAccount);
		Account* getAccount();

		System();
		~System();


		/* Access the reservation calendar
		*/
		IReservationCalendar& getCalendar();
	};

}

#pragma once

#include"ReservationCalendar.h"
#include"ISystem.h"
#include "Account.h"
#include"Library.h"

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
		/* System data libraries*/
		std::vector<Library> _libraries;

		/* Vector holding user accounts */
		std::vector<Account> accounts;

		/* Reference to currently logged in account */
		Account* signedInAs;

		/* Public access functions.
		*/
	public:
		virtual bool login(std::string username, std::string password);
		virtual void addAccount(lic::Account newAccount);
		/* Access the logged in account in the system
		*/
		IAccount* getAccount();

		virtual std::vector<Account> getAccounts();

		System();
		~System();


		/* Access the reservation calendar
		*/
		virtual IReservationCalendar& getCalendar();
		/* Access the current date
		*/
		virtual Date getDate();

		/* Access a library from the system
		*/
		virtual ILibrary& getLibrary(const std::string& library);
	};

}

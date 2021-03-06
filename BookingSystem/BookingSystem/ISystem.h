#pragma once

#include"IReservationCalendar.h"
#include"ILibrary.h"
#include"IAccount.h"
#include"Account.h"
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

		/* Login to the system.
		*/
		virtual bool login(std::string username, std::string password)= 0;
		/* Add account to the system
		*/
		virtual void addAccount(lic::Account newAccount) = 0;

		/* Access the reservation calendar
		*/
		virtual IReservationCalendar& getCalendar() = 0;

		/* Access the current date
		*/
		virtual Date getDate() = 0;

		/* Access a library from the system
		*/
		virtual ILibrary& getLibrary(const std::string& library) = 0;
		/* Access the logged in account in the system
		*/
		virtual IAccount* getAccount() = 0;

		virtual std::vector<Account> getAccounts() = 0;

		virtual ~ISystem() {};
	};

}
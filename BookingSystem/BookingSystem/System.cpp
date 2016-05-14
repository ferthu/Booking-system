#include "System.h"

namespace lic {

	System::System()
		: _calendar(Date(2016, 05, 14))
	{
		signedInAs = nullptr;
	}


	System::~System()
	{
	}


	/* Access the reservation calendar
	*/
	IReservationCalendar& System::getCalendar() {
		return _calendar;
	}
	/* Access the current date
	*/
	Date System::getDate() {
		return _calendar.getDate();
	}

	bool System::login(std::string username, std::string password)
	{
		std::vector<std::string> profile;

		for (int i = 0; i < accounts.size(); i++)
		{
			profile = accounts[i].getProfile();

			// check for correct username and password
			if (profile[0] == username && profile[1] == password)
			{
				signedInAs = &(accounts[i]);

				return true;
			}
		}
		return false;
	}

	void System::addAccount(lic::Account newAccount)
	{
		accounts.push_back(newAccount);
	}

	Account* System::getAccount()
	{
		return signedInAs;
	}
}
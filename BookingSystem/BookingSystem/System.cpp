#include "System.h"

namespace lic {

	System::System()
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
}
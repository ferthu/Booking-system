#include "System.h"

namespace lic {

	System::System()
		: _calendar(Date(2016, 05, 14), 5, 2), _libraries()
	{
		signedInAs = nullptr;

		//Add system libraries:
		_libraries.push_back(Library("")); //Dummy library.
		_libraries.push_back(Library(lib::GAMELIBRARY));
		_libraries.push_back(Library(lib::MENTORLIBRARY));
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
	/* Access a library from the system
	*/
	ILibrary& System::getLibrary(const std::string& library) {

		for (unsigned int i = 0; i < _libraries.size(); i++) {
			if (_libraries[i]._name == library)
				return _libraries[i];
		}
		/*Return the dummy library....*/
		return _libraries[0];
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

	IAccount* System::getAccount()
	{
		return signedInAs;
	}
}
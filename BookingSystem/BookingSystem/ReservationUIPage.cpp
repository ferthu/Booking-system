#include "ReservationUIPage.h"
#include<iostream>
#include"ReservationCalendar.h"

namespace ui {


	ReservationUIPage::ReservationUIPage(const UIState& state, lic::System& sys, const std::vector<std::string>& service)
		: UIPage(state, sys), _reservation(service)
	{
	}


	ReservationUIPage::~ReservationUIPage()
	{
	}

	lic::Date ReservationUIPage::selectDate() {
		std::cout << "Enter a reservation date: ";
		std::cout << "Year: ";
		int year = getNumberInput(2016, 2018);
		std::cout << "Month: ";
		int month = getNumberInput(1, 12);
		std::cout << "Day: ";
		int day = getNumberInput(0, lic::DAYPERMONTH[month - 1]);

		_reservation._date = lic::Date(year, month, day);
	}

	void ReservationUIPage::selectOptions(lic::Reservation& res) {
		std::cout << "Enter reservation options: " << std::endl;
		std::cout << "Number of players: ";
		int pCount = getNumberInput(1, 20);
		std::cout << "Mentor (y/n): ";
		bool mentor = getTrueFalse();

		_reservation._players = pCount;
		_reservation._services.push_back("Mentor");
	}
	lic::Time ReservationUIPage::selectTime(std::shared_ptr<std::vector<lic::Time>> available) {

		std::cout << "Available time slots: " << std::endl;
		for (unsigned int i = 0; i < available->size(); i++) 
			std::cout << i << ". " << (*available)[i]._hour << '.' << (*available)[i]._minute << std::endl;
		std::cout << "Select time slot: ";
		int timeSelected = getNumberInput(1, available->size());
		return (*available)[timeSelected];
	}
	void ReservationUIPage::lastStep() {

	}

	void ReservationUIPage::runPage()
	{
		std::cout << "Reserve service " + _reservation._services[0] + "\n";

		selectOptions(_reservation);
		lic::Date d = selectDate();

		std::shared_ptr<std::vector<lic::Time>> available = sys.getCalendar().freeReservations(_reservation, d);



		bool success = false;
		std::string username;
		std::string password;

		tryLogin(username, password);

		while (username != "0" && !(success = sys.login(username, password))) {
			std::cout << "Unrecognized username or password.\n\n";

			tryLogin(username, password);
		}

		if (username != "0")
		{
			std::cout << "Logged in as " << username << ".";
			getchar();
		}
		std::cout << "\nAlready signed in as " << sys.getAccount()->getName() << ".";
		getchar();

		state.setNextPage(new ui::MainUIPage(state, sys));
	}

}

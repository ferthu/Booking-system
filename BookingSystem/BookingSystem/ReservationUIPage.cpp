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

	void ReservationUIPage::selectDate() {
		std::cout << "Enter date a reservation date: ";
		std::cout << "Enter Year: ";
		int year = getNumberInput(2016, 2018);
		std::cout << "Enter Month: ";
		int month = getNumberInput(1, 12);
		std::cout << "Enter Day: ";
		int day = getNumberInput(0, lic::DAYPERMONTH[month - 1]);

		_reservation._date = lic::Date(year, month, day);
	}

	void ReservationUIPage::selectOptions() {


	}
	void ReservationUIPage::selectTime() {

	}
	void ReservationUIPage::lastStep() {

	}

	void ReservationUIPage::runPage()
	{
		std::cout << "Booking System\n\n";
		std::cout << "Reservation\n";

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

#include "ReservationUIPage.h"
#include<iostream>
#include"ReservationCalendar.h"
#include"ReservationTimeUIPage.h"
#include"UIState.h"

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
		//If mentor is selected remove it from the service list to not add it again:
		for (int i = 0; i < _reservation._services.size(); i++){
			if (_reservation._services[i] == MENTORSERVICENAME) {
				_reservation._services.erase(_reservation._services.begin() + i);
				break;
			}
		}
		std::cout << "Enter reservation options: " << std::endl;
		std::cout << "Number of players: ";
		int pCount = getNumberInput(1, 20);
		std::cout << "Mentor (y/n): ";
		bool mentor = getTrueFalse();

		_reservation._players = pCount;
		if(mentor)
			_reservation._services.push_back(MENTORSERVICENAME);
	}

	void ReservationUIPage::runPage()
	{
		std::cout << "Reserve service " + _reservation._services[0] + "\n";
		std::cout << "Reserve service " + _reservation._services[0] + "\n";
		

		selectOptions(_reservation);
		_reservation._date = selectDate();

		state.setNextPage(new ReservationTimeUIPage(state, sys, _reservation));
	}

}

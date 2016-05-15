/* Mattias Fredriksson
*/

#include "ReservationUIPage.h"
#include<iostream>
#include"ReservationCalendar.h"
#include"ReservationTimeUIPage.h"
#include"MainUIPage.h"
#include"UIState.h"
#include"DisplayReservationFunc.h"

namespace ui {


	ReservationUIPage::ReservationUIPage(const UIState& state, lic::ISystem& sys, const std::vector<std::string>& service)
		: UIPage(state, sys), _reservation(sys.getDate(), 1, service)
	{
	}

	ReservationUIPage::ReservationUIPage(const UIState& state, lic::ISystem& sys, const std::string& service)
		: UIPage(state, sys), _reservation(sys.getDate(), 1, service)
	{

	}

	ReservationUIPage::ReservationUIPage(const UIState& state, lic::ISystem& sys, const lic::Reservation res)
		: UIPage(state, sys), _reservation(res._date, res._players, res._services) {

	}


	ReservationUIPage::~ReservationUIPage()
	{
	}


	/* Display date selection 
	*/
	lic::Date ReservationUIPage::selectDate() {

		bool loop = true;

		int year, month, day;

		while (loop)
		{
			std::cout << "Enter a reservation date:\n";
			std::cout << "Year: ";
			year = getNumberInput(2016, 2018);
			std::cout << "Month: ";
			month = getNumberInput(1, 12);
			std::cout << "Day: ";
			day = getNumberInput(0, lic::DAYPERMONTH[month - 1]);

			// check if date is today or in the future
			if (sys.getDate()._year <= year)
				if (sys.getDate()._month <= month)
					if (sys.getDate()._day <= day)
						loop = false;

			if (loop)
				std::cout << "Invalid date!\n";
		}

		return lic::Date(year, month, day);
	}
	/* Display option selection
	*/
	void ReservationUIPage::selectOptions(const lic::Reservation& res) {
		//If mentor is selected remove it from the service list to not add it again:
		for (int i = 0; i < _reservation._services.size(); i++){
			if (_reservation._services[i] == ser::MENTOR) {
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
			_reservation._services.push_back(ser::MENTOR);

		std::cout << "\n\n";
	}
	/* Displays selection menu
	*/
	int ReservationUIPage::displaySelection() {
		std::cout << "Reservation options: " << std::endl;
		std::cout << "1. Change options" << std::endl;
		std::cout << "2. Change date" << std::endl;
		std::cout << "3. Next step" << std::endl;
		std::cout << "4. Main menu" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter option: " << std::endl;
		return getNumberInput(1, 4);
	}

	void ReservationUIPage::runPage()
	{
		//Reservation is set initially for current date:
		_reservation._date = sys.getDate();

		bool loop = true;
		while (loop) {
			std::cout << "Booking System\n\n";
			std::cout << "\n\n";
			//Display reservation information:
			displayServices(_reservation);
			displayDate(_reservation);
			displayPlayer(_reservation);
			displayCost(_reservation, sys);
			std::cout << std::endl << std::endl << std::endl;

			int option = displaySelection();
			std::cout << "\n";

			switch (option)
			{
			case 1:
				selectOptions(_reservation);
				break;
			case 2:
				_reservation._date = selectDate();
				break;
			case 3:
				//Set next page and end loop
				state.setNextPage(new ReservationTimeUIPage(state, sys, _reservation));
				loop = false;
				break;
			case 4:
				//Set main page and end function
				state.setNextPage(new MainUIPage(state, sys));
				loop = false;
				break;
			default:
				break;
			}
			//Break between pages:
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}

	}

}

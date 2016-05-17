/* Mattias Fredriksson
*/

#include "ReservationTimeUIPage.h"
#include<iostream>
#include"ReservationCalendar.h"
#include"ReservationUIPage.h"
#include"ReservationFinal.h"
#include"UIState.h"
#include"DisplayReservationFunc.h"

namespace ui {

	ReservationTimeUIPage::ReservationTimeUIPage(const UIState& state, lic::ISystem& sys, const lic::Reservation& res)
		: UIPage(state, sys), _reservation(res._date, res._players, res._services)
	{

	}


	ReservationTimeUIPage::~ReservationTimeUIPage()
	{
	}


	void ReservationTimeUIPage::runPage()
	{

		std::shared_ptr<std::vector<lic::Time>> available = sys.getCalendar().freeReservations(_reservation, _reservation._date);
		std::cout << "Select an available time slot:" << std::endl;
		for (unsigned int i = 0; i < available->size(); i++) {
			std::cout << i + 1 << ".  ";
			if (i + 1 < 10) //Even the character count
				std::cout << ' ';
			displayTime(available->operator[](i));
			std::cout << std::endl;
		}
		std::cout << "0. Back" << std::endl;
		std::cout << "Select time slot: ";
		int timeSelected = getNumberInput(0, (int)available->size());

		//If 0 was selected go back to reservation settings.
		if (timeSelected == 0)
			state.setNextPage(new ReservationUIPage(state, sys, _reservation._services));
		else
		{
			lic::Time t = (*available)[timeSelected - 1];

			bool success = sys.getCalendar().reserve(_reservation, _reservation._date, t);
			//If reservation was not a success the process needs to be done again
			if (!success) {
				state.setNextPage(new ReservationTimeUIPage(state, sys, _reservation), false);
				clearPage();
				std::cout << "Error: reservation time was occupied during selection process.\n\n\n\n";
				return;
			}
			else {
				state.setNextPage(new ReservationFinal(state, sys, _reservation));
			}
		}
	}

}
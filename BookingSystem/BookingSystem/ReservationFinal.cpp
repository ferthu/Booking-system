/* Mattias Fredriksson
*/
#include "ReservationFinal.h"
#include"DisplayReservationFunc.h"
#include<iostream>
#include"UIState.h"
#include"MainUIPage.h"
#include"ReservationUIPage.h"

namespace ui {


	ReservationFinal::ReservationFinal(const UIState& state, lic::System& sys, const lic::Reservation& res)
		: UIPage(state, sys), _reservation(res)
	{
	}


	ReservationFinal::~ReservationFinal()
	{
	}


	void ReservationFinal::runPage() {
		
		std::cout << "Reservation Details:\n\n";
		displayReservation(_reservation, sys);

		std::cout << "\n\n\n\n";
		std::cout << "1. Confirm\n";
		std::cout << "2. Edit\n";
		std::cout << "3. Cancel\n";
		
		int option = getNumberInput(1, 2);

		if (option == 1) {
			//Completed reservation go back to main page.
			lic::IAccount* acc = sys.getAccount();
			std::string& accountName = acc != nullptr ? acc->getName() : "Unregistrered";
			sys.getCalendar().finalize(_reservation, accountName);
			state.setNextPage(new MainUIPage(state, sys));
		}
		else if (option == 2) {
			//Remove the reservation and go to reservation edit stage.
			sys.getCalendar().editReservation(_reservation);
			state.setNextPage(new ReservationUIPage(state, sys, _reservation));
		}
		else if (option == 3) {
			//Reservation canceled, remove it and go back to main page.
			sys.getCalendar().editReservation(_reservation);
			state.setNextPage(new MainUIPage(state, sys));
		}
	}

}

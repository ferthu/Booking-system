#include"DisplayReservationFunc.h"
#include<iostream>


namespace ui {


	/* Display the date
	*/
	void displayDate(const lic::Reservation& res) {
		std::cout << "Date: " << res._date._year << '-' << res._date._month << '-' << res._date._day << std::endl;
	}
	/* Display the time
	*/
	void displayTime(const lic::Reservation& res) {
		std::cout << "Time: " << res._time._hour << '.' << res._time._minute << std::endl;
	}
	/* Display the services
	*/
	void displayServices(const lic::Reservation& res) {
		std::cout << "Services:" << std::endl;
		for (int i = 0; i < res._services.size(); i++)
			std::cout << i + 1 << ". " << res._services[0] << std::endl;
	}
	/* Display the player count
	*/
	void displayPlayer(const lic::Reservation& res) {
		std::cout << "Number of players: " << res._players << std::endl << std::endl;
	}
	/* Display service cost
	*/
	void displayCost(const lic::Reservation& res, lic::ISystem& sys) {
		//Calculate total cost:
		Price cost = 0;
		lic::ILibrary& lib = sys.getLibrary(lib::RESERVATIONLIBRARY);
		for (unsigned int i = 0; i < res._services.size(); i++) {
			lic::Service service;
			if (lib.getService(res._services[i], service)) {
				cost += service._price * res._players;
			}
		}
		std::cout << "Total cost: " << cost.getPrice() << std::endl;
	}
	/* Display payment option for the reservation
	*/
	void displayPaymentOption(const lic::Reservation& res) {
		std::cout << "Payment option: In store" << std::endl;;
	}

	/* Function displaying a reservation
	*/
	void  displayReservation(const lic::Reservation& res, lic::ISystem& sys) {
		displayServices(res);
		displayDate(res);
		displayTime(res);
		displayPlayer(res);
		displayPaymentOption(res);
		displayCost(res, sys);
	}

}
/* Mattias Fredriksson
*/

#include"DisplayReservationFunc.h"
#include<iostream>


namespace ui {


	/* Display the date
	*/
	void displayDate(const lic::Reservation& res) {
		std::cout << "Date: " << res._date._year << '-' << res._date._month << '-' << res._date._day << std::endl;
	}
	/* Display the time var (does not call newline)
	*/
	void displayTime(lic::Time t) {
		if (t._hour < 10)
			std::cout << '0';
		std::cout << t._hour;
		std::cout << ':';
		if(t._minute < 10)
			std::cout << '0';
		std::cout << t._minute;
	}
	/* Display the time
	*/
	void displayTime(const lic::Reservation& res) {
		std::cout << "Time: ";
		displayTime(res._time);
		std::cout << std::endl;
	}
	/* Display the services
	*/
	void displayServices(const lic::Reservation& res) {
		std::cout << "Services:" << std::endl;
		for (int i = 0; i < res._services.size(); i++)
			std::cout << i + 1 << ". " << res._services[i]._name << std::endl;
		std::cout <<  std::endl;
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
		for (unsigned int i = 0; i < res._services.size(); i++) {
			lic::ILibrary& lib = sys.getLibrary(res._services[i]._type);
			lic::Service service;
			if (lib.getService(res._services[i]._name, service)) {
				cost += service._price * res.getReservationCount(i);
			}
		}
		std::cout << "Total cost: " << cost.getPrice() << '$' << std::endl;
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
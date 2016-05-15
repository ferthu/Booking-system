#pragma once

#include"Reservation.h"
#include"ISystem.h"

/* Functions to help display reservation data in the console window
*/

namespace ui {

	/* Display service cost
	*/
	void displayCost(const lic::Reservation& res, lic::ISystem& sys);
	/* Display payment option for the reservation
	*/
	void displayPaymentOption(const lic::Reservation& res);

	/* Function displaying a reservation
	*/
	void  displayReservation(const lic::Reservation& res, lic::ISystem& sys);
	/* Display the date (does not call newline)
	*/
	void displayDate(const lic::Reservation& res);
	/* Display the time for the reservation
	*/
	void displayTime(const lic::Reservation& res);
	/* Display the time var
	*/
	void displayTime(lic::Time t);
	/* Display the services
	*/
	void displayServices(const lic::Reservation& res);
	/* Display the player count
	*/
	void displayPlayer(const lic::Reservation& res);
	

}
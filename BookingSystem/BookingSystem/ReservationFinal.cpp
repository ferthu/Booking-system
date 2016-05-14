#include "ReservationFinal.h"
#include"DisplayReservationFunc.h"
#include<iostream>

namespace ui {


	ReservationFinal::ReservationFinal(const UIState& state, lic::System& sys, const lic::Reservation& res)
		: UIPage(state, sys), _reservation(res)
	{
	}


	ReservationFinal::~ReservationFinal()
	{
	}


	void ReservationFinal::runPage() {
		
		displayReservation(_reservation);
		



	}

}

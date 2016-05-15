#pragma once
#include "UIPage.h"

namespace ui {

	/* Ui page dedicated to selecting the time during the reservation process.
	*/
	class ReservationTimeUIPage :
		public UIPage
	{

		lic::Reservation _reservation;

	public:
		ReservationTimeUIPage(const UIState& state, lic::System& sys, const lic::Reservation& res);
		virtual ~ReservationTimeUIPage();


		virtual void runPage();

	};

}


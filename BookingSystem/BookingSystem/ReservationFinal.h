#pragma once
#include "UIPage.h"

namespace ui {

	class ReservationFinal :
		public UIPage
	{
	private:
		lic::Reservation _reservation;

	public:
		ReservationFinal(const UIState& state, lic::System& sys, const lic::Reservation& res);
		virtual ~ReservationFinal();

		virtual void runPage();
	};

}


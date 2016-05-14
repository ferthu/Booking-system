/* Mattias Fredriksson
*/

#pragma once
#include "UIPage.h"
#include"Reservation.h"

namespace ui {

	class ReservationUIPage :
		public UIPage
	{
	private:

		lic::Reservation _reservation;


		void selectDate();
		void selectOptions();
		void selectTime();
		void lastStep();

	public:
		ReservationUIPage(const UIState& state, lic::System& sys, const std::vector<std::string>& service);
		~ReservationUIPage();


		virtual void runPage();
	};

}

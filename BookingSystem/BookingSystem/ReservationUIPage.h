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


		lic::Date selectDate();
		void selectOptions(lic::Reservation& res);
		lic::Time selectTime(std::shared_ptr<std::vector<lic::Time>> available);
		void lastStep();

	public:
		ReservationUIPage(const UIState& state, lic::System& sys, const std::vector<std::string>& service);
		~ReservationUIPage();


		virtual void runPage();
	};

}

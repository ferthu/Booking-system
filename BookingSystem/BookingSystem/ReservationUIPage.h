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

		/* Data holding the reservation information
		*/
		lic::Reservation _reservation;


		lic::Date selectDate();
		void selectOptions(const lic::Reservation& res);
		int displaySelection();

	public:
		ReservationUIPage(const UIState& state, lic::System& sys, const std::vector<std::string>& service);
		ReservationUIPage(const UIState& state, lic::System& sys, const std::string& service);
		ReservationUIPage(const UIState& state, lic::System& sys, const lic::Reservation reservation);
		virtual ~ReservationUIPage();


		virtual void runPage();
	};

}

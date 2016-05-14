/* Mattias Fredriksson
*/

#pragma once
#include "UIPage.h"
#include"Reservation.h"

namespace ui {

	static const std::string MENTORSERVICENAME = "Mentor";

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
		~ReservationUIPage();


		virtual void runPage();
	};

}

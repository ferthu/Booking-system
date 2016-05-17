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
		ReservationUIPage(const UIState& state, lic::ISystem& sys, const std::vector<ServiceType>& service);
		ReservationUIPage(const UIState& state, lic::ISystem& sys, const ServiceType& service);
		ReservationUIPage(const UIState& state, lic::ISystem& sys, const lic::Reservation reservation);
		virtual ~ReservationUIPage();


		virtual void runPage();
	};

}

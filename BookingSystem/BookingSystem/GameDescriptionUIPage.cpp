#include "GameDescriptionUIPage.h"
#include "LibraryUIPage.h"
#include "ReservationUIPage.h"
#include "Reservation.h"
#include "Service.h"

ui::GameDescriptionUIPage::GameDescriptionUIPage(const UIState& state, lic::ISystem& sys, const lic::Service service)
	: UIPage(state, sys)
{
	_service = service;
}

void ui::GameDescriptionUIPage::runPage()
{
	std::cout << "Booking System\n\n";
	std::cout << _service._name << "\n\n";
	std::cout << "Description: " << _service._description << "\n\n";
	std::cout << "0. Go Back\n";
	std::cout << "1. Book Game\n";
	std::cout << "\nSelect an option: ";

	int selection = getNumberInput(0, 1);

	if (selection == 0)
	{
		state.setNextPage(new ui::LibraryUIPage(state, sys));
	}
	else
	{
		state.setNextPage(new ui::ReservationUIPage(state, sys, _service._name));
	}
}
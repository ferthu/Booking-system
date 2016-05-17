#include "GameDescriptionUIPage.h"
#include "LibraryUIPage.h"
#include "ReservationUIPage.h"
#include "Reservation.h"
#include "Service.h"
#include"ViewReviewsUIPage.h"

ui::GameDescriptionUIPage::GameDescriptionUIPage(const UIState& state, lic::ISystem& sys, const lic::Service service)
	: UIPage(state, sys)
{
	_service = service;
}

void ui::GameDescriptionUIPage::runPage()
{
	std::cout << _service._name << "\n\n";
	std::cout << "Description: \n" << _service._description << "\n\n";
	std::cout << "Price: " << _service._price._amount << std::endl;
	std::cout << "Rating: " << _service._rating << std::endl;
	std::cout << "Required age: " << _service._requiredAge << std::endl;
	std::cout << "Tags: ";
	if (_service._tags.size() > 0) {
		for (int i = 0; i < _service._tags.size(); i++) {
			std::cout << _service._tags[i] << ", ";
		}
	}

	std::cout << "\n\n0. Go Back\n";
	std::cout << "1. View reviews\n";
	std::cout << "2. Book Game\n";
	std::cout << "\nSelect an option: ";
	int selection = getNumberInput(0, 2);
	lic::Filter f;
	if (selection == 0)
	{
		state.setNextPage(new ui::LibraryUIPage(state, sys, f));
	}
	else if(selection == 1)
	{
		state.setNextPage(new ui::ViewReviewsUIPage(state, sys, _service));
	}
	else
	{
		state.setNextPage(new ui::ReservationUIPage(state, sys, ServiceType(_service._name, ser::GAME)));
	}
}
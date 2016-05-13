#include "MainUIPage.h"
#include "LoginUIPage.h"

void ui::MainUIPage::runPage()
{
	std::cout << "Booking System\n\n";
	std::cout << "1. Log in\n";
	std::cout << "2. Quit\n";
	std::cout << "\nSelect an option: ";

	int selection = getNumberInput(1, 2);

	switch (selection)
	{
	case 1:
		// todo: check if logged in

		state.setNextPage(new ui::LoginUIPage(state, sys));
		break;

	case 2:
		state.quitUI();
		break;
	}
}
#include "MainUIPage.h"
#include "LoginUIPage.h"
#include "LibraryUIPage.h"
#include "GameDescriptionUIPage.h"

void ui::MainUIPage::runPage()
{
	std::cout << "Booking System\n\n";
	std::cout << "1. Log In\n";
	std::cout << "2. Browse Library\n";
	std::cout << "3. Quit\n";
	std::cout << "\nSelect an option: ";

	int selection = getNumberInput(1, 3);

	switch (selection)
	{
	case 1:
		state.setNextPage(new ui::LoginUIPage(state, sys));
		break;

	case 2:
		state.setNextPage(new ui::LibraryUIPage(state, sys));
		break;

	case 3:
		state.quitUI();
		break;
	}
}
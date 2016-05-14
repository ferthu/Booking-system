#include "GameDescriptionUIPage.h"
#include "LibraryUIPage.h"

void ui::GameDescriptionUIPage::runPage()
{
	std::cout << "Booking System\n\n";
	std::cout << "Game Title\n\n";
	std::cout << "Description: " /* << game description */ << "\n\n";
	std::cout << "0. Go Back\n";
	std::cout << "1. Book Game\n";
	std::cout << "\nSelect an option: ";

	int selection = getNumberInput(0, 1);

	if (selection == 0)
	{
		// go back to library
	}
	else
	{
		// go to booking page
	}
}
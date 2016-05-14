#include "LibraryUIPage.h"
#include "MainUIPage.h"

void ui::LibraryUIPage::runPage()
{
	std::cout << "Booking System\n\nLibrary\n\n";

	// todo: list games
	std::cout << "<List of games>\n";

	std::cout << "\nSelect a game (or '0' to go back): ";
	int selection = getNumberInput(0, 0);

	if (selection == 0)
	{
		state.setNextPage(new ui::MainUIPage(state, sys));
	}
	else
	{
		// todo: go to selected game's description page
	}
}
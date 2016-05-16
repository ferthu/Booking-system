#include "MainUIPage.h"
#include "LoginUIPage.h"
#include "LibraryUIPage.h"
#include "ReportUIPage.h"
#include "GameDescriptionUIPage.h"

void ui::MainUIPage::runPage()
{
	std::cout << "Booking System\n\n";
	std::cout << "1. Log In\n";
	std::cout << "2. Browse Library\n";
	std::cout << "3. Reservation Report\n";
	std::cout << "4. Quit\n";
	std::cout << "\nSelect an option: ";

	int selection = getNumberInput(1, 3);
	lic::Filter f;
	switch (selection)
	{
	case 1:
		state.setNextPage(new ui::LoginUIPage(state, sys));
		break;

	case 2:
		state.setNextPage(new ui::LibraryUIPage(state, sys, f));
		break;

	case 3:
		state.setNextPage(new ui::ReportUIPage(state, sys));
		break;

	case 4:
		state.quitUI();
		break;
	}
}
#include "LibraryUIPage.h"
#include "MainUIPage.h"
#include"GameDescriptionUIPage.h"

void ui::LibraryUIPage::runPage()
{
	std::cout << "Library\n\n";

	lic::Filter f;
	//Fetch list:
	std::shared_ptr<std::vector<lic::Service>>& list = sys.getLibrary(lib::GAMELIBRARY).getServices(f);

	//Print list:
	for (unsigned int i = 0; i < list->size(); i++) 
		std::cout << i + 1 << ". " << list->operator[](i)._name << std::endl;

	std::cout << "\n\nSelect a game (or '0' to go back): ";
	int selection = getNumberInput(0, (int)list->size());

	if (selection == 0)
	{
		state.setNextPage(new ui::MainUIPage(state, sys));
	}
	else
	{
		state.setNextPage(new ui::GameDescriptionUIPage(state, sys, list->operator[](selection - 1)));
	}
}
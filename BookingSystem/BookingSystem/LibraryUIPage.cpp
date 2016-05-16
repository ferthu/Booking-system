#include "LibraryUIPage.h"
#include "MainUIPage.h"
#include "FilterUIPage.h"
#include"GameDescriptionUIPage.h"

ui::LibraryUIPage::LibraryUIPage(const UIState& state, lic::ISystem& sys, const lic::Filter filter)
	: UIPage(state, sys)
{
	_filter = filter;
}

void ui::LibraryUIPage::runPage()
{
	std::cout << "Library\n\n";

	//Fetch list:
	std::shared_ptr<std::vector<lic::Service>>& list = sys.getLibrary(lib::GAMELIBRARY).getServices(_filter);
	
	std::cout << "1: Apply a filter to the list \n\n";

	//Print list:
	for (unsigned int i = 0; i < list->size(); i++)
		std::cout << i + 2 << ". " << list->operator[](i)._name << std::endl;

	std::cout << "\n\nSelect a game, (or '0' to go back): ";
	int selection = getNumberInput(0, (int)list->size() + 1);

	if (selection == 0)
	{
		state.setNextPage(new ui::MainUIPage(state, sys));
	}
	else if (selection == 1)
	{
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
	}
	else
	{
		state.setNextPage(new ui::GameDescriptionUIPage(state, sys, list->operator[](selection - 2)));
	}
}
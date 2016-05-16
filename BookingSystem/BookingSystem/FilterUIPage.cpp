#include "FilterUIPage.h"
#include "LibraryUIPage.h"
#include "MainUIPage.h"
#include "Filter.h"

ui::FilterUIPage::FilterUIPage(const UIState& state, lic::ISystem& sys, const lic::Filter filter)
	: UIPage(state, sys)
{
	_filter = filter;
}

void ui::FilterUIPage::runPage()
{
	std::cout << "Select number to change filter\n";
	std::cout << "1. Search word: " << _filter._text << std::endl;
	std::cout << "2. Price: " << _filter._maxPrice << std::endl;
	std::cout << "3. Rating: " << _filter._rating << std::endl;
	std::cout << "4. Age restriction: " << _filter._ageRestriction << std::endl;
	std::cout << "5. Tags: ";
	if (_filter._tags.size() > 0) {
		for (int i = 0; i < _filter._tags.size(); i++) {
			std::cout << _filter._tags[i] << ", ";
		}
	}
	std::cout << "\n6. Clear tags";
	std::cout << "\n\n'7' Apply filter, (or '0' to clear filter and go back)";
	int selection = getNumberInput(0, 7);
	lic::Filter f;
	std::string word;
	int integer;
	switch (selection)
	{
	case 0:
		state.setNextPage(new ui::LibraryUIPage(state, sys, f));
		break;

	case 1:
		std::cout << "\nEnter a search word: ";
		word = getWordInput();
		_filter._text = word;
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
		break;

	case 2:
		std::cout << "\nEnter max price: ";
		integer = getNumberInput(0, 100000);
		_filter._maxPrice = integer;
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
		break;

	case 3:
		std::cout << "\nEnter min rating(0-100): ";
		integer = getNumberInput(0, 100);
		_filter._rating = integer / (float)100;
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
		break;

	case 4:
		std::cout << "\nEnter Age restriction (0-18): ";
		integer = getNumberInput(0, 18);
		_filter._ageRestriction = integer;
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
		break;

	case 5:
		std::cout << "\nEnter a tag: ";
		word = getWordInput();
		_filter._tags.push_back(word);
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
		break;

	case 6:
		_filter._tags.clear();
		state.setNextPage(new ui::FilterUIPage(state, sys, _filter));
		break;

	case 7:
		state.setNextPage(new ui::LibraryUIPage(state, sys, _filter));
		break;
	}

	std::cout << std::string(100, '\n');
}

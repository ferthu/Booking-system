/* Created by: Timmie
*/

#include <iostream>
#include "UIPage.h"
#include"UIState.h"

using namespace std;

namespace ui {

	void UIPage::clearInputBuffer()
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	/* Clears the page by adding line breakers
	*/
	void UIPage::clearPage() {
		std::cout << std::string(100, '\n');
	}

	bool UIPage::getTrueFalse()
	{
		char response;
		cin >> response;
		clearInputBuffer();

		while (response != 'y' && response != 'Y' && 
			response != 'n'&& response != 'N')
		{
			cout << "Enter 'y' or 'n': ";
			cin >> response;
			clearInputBuffer();
		}

		return response == 'y' || response == 'Y';
	}
	int UIPage::getNumberInput(int min, int max)
	{
		int number;
		cin >> number;
		clearInputBuffer();

		while (number < min || number > max)
		{
			cout << "Enter a number between " << min << " and " << max << ": ";
			cin >> number;
			clearInputBuffer();
		}

		return number;
	}
	string UIPage::getWordInput()
	{
		string str;

		cin >> str;
		clearInputBuffer();

		return str;
	}


	UIPage::UIPage(const UIState& state, lic::ISystem& sys)
		: state(state), sys(sys)
	{}

	UIPage::~UIPage()
	{
	}

}
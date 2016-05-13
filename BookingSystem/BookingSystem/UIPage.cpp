/* Created by: Timmie
*/

#include <iostream>
#include "UIPage.h"

using namespace std;

namespace ui {

	void UIPage::clearInputBuffer()
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
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

	UIPage::UIPage(const UIState& state)
		: state(state)
	{}

	UIPage::~UIPage()
	{
	}

}
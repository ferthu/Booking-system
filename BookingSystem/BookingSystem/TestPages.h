#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

using namespace std;

// used for testing

class Test2UIPage : public UIPage
{
	void runPage()
	{
		cout << "Enter a word: ";

		string str = getWordInput();

		cout << "Entered " << str << "." << endl;

		UIState::getInstance()->quitUI();
	}
};

class Test1UIPage : public UIPage
{
	void runPage()
	{
		cout << "Enter a number between 5 and 7: ";

		int num = getNumberInput(5, 7);

		cout << "Entered " << num << "." << endl;

		UIState::getInstance()->setNextPage(new Test2UIPage());
	}
};
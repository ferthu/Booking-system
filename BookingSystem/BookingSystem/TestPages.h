/* Created by: Timmie
*/
#pragma once

#include <iostream>

#include "System.h"
#include "UIPage.h"
#include "UIState.h"

using namespace std;

namespace ui {

	// used for testing

	class Test2UIPage : public UIPage
	{
	public:
		Test2UIPage(const UIState& state, lic::System& sys)
			: UIPage(state, sys) {}

		void runPage()
		{
			cout << "Enter a word: ";

			string str = getWordInput();

			cout << "Entered " << str << "." << endl;

			state.quitUI();
		}
	};

	class Test1UIPage : public UIPage
	{
	public:
		Test1UIPage(const UIState& state, lic::System& sys)
			: UIPage(state, sys){}

		void runPage()
		{
			cout << "Enter a number between 5 and 7: ";

			int num = getNumberInput(5, 7);

			cout << "Entered " << num << "." << endl;

			state.setNextPage(new Test2UIPage(state, sys));
		}
	};

}
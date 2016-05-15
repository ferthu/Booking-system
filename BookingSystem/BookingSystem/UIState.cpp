/* Created by: Timmie
*/
#include "UIState.h"
#include "System.h"
#include <iostream>
#include"MainUIPage.h"

namespace ui {

	UIState::UIState(lic::ISystem& sys)
		: sys(sys)
	{}
	UIState::~UIState() {
		if(currentPage != nullptr)
			delete currentPage;
		if(nextPage != nullptr)
			delete nextPage;
	}

	void UIState::runUI(UIPage* firstPage)
	{
		currentPage = firstPage;
		nextPage = nullptr;
		quit = false;

		std::cout << std::string(100, '\n');
		currentPage->runPage();
		std::cout << std::string(100, '\n');

		while (!quit)
		{
			delete currentPage;

			currentPage = nextPage;
			nextPage = nullptr;

			currentPage->runPage();
			currentPage->clearPage(); //Clear console window

			if (nextPage == nullptr && !quit)
				nextPage = new MainUIPage(*this, sys);
		}
	}

	void UIState::setNextPage(UIPage* next, bool clearPage) const
	{
		_clearPage = clearPage;
		nextPage = next;
	}


	void UIState::quitUI() const
	{
		quit = true;
	}


}
/* Created by: Timmie
*/
#include "UIState.h"
#include "System.h"
#include <iostream>

namespace ui {

	UIState::UIState()
	{
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
			std::cout << std::string(100, '\n');

			if (nextPage == nullptr && !quit)
				throw("No next page selected!");
		}

		delete currentPage;
	}

	void UIState::setNextPage(UIPage* next) const
	{
		nextPage = next;
	}


	void UIState::quitUI() const
	{
		quit = true;
	}


}
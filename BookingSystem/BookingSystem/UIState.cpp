/* Created by: Timmie
*/
#include "UIState.h"

namespace ui {

	UIState::UIState()
	{
	}

	void UIState::runUI(UIPage* firstPage)
	{
		currentPage = firstPage;
		nextPage = nullptr;
		quit = false;

		currentPage->runPage();

		while (!quit)
		{
			delete currentPage;

			currentPage = nextPage;
			nextPage = nullptr;

			currentPage->runPage();

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
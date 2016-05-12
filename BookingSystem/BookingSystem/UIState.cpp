/* Created by: Timmie
*/
#include "UIState.h"

namespace ui {

	void UIState::swichPage(UIPage* newPage)
	{
		delete currentPage;

		currentPage = newPage;
		currentPage->runPage();
	}

	void UIState::initialize(UIPage* firstPage)
	{
		currentPage = firstPage;
		currentPage->runPage();
	}

}
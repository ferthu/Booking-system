/* Created by: Timmie
*/
#ifndef UISTATE_H
#define UISTATE_H

#include "UIPage.h"

namespace ui {

	class UIState
	{
	private:
		UIPage* currentPage;

	public:
		void swichPage(UIPage* newPage);
		void initialize(UIPage* firstPage);
	};

}

#endif
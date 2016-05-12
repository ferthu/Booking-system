#ifndef UISTATE_H
#define UISTATE_H

#include "UIPage.h"

class UIState
{
private:
	static UIPage* currentPage;

public:
	static void swichPage(UIPage* newPage);
	static void initialize(UIPage* firstPage);
};

#endif
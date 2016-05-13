#ifndef UISTATE_H
#define UISTATE_H

#include "UIPage.h"

class UIState
{
private:
	static UIState* instance;

	UIPage* currentPage;
	UIPage* nextPage;
	bool quit;
	UIState();

public:
	static void initialize();
	static void cleanup();
	static UIState* getInstance();

	void quitUI();
	void setNextPage(UIPage* next);

	void runUI(UIPage* firstPage);
};



#endif
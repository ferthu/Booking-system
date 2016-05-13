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

		/* Mutable represents variables able to change from const functions
		*/

		/* Holds the next page when waiting to finish executing the old function
		*/
		mutable UIPage* nextPage;
		/* If a call to exit the ui is called.
		*/
		mutable bool quit;

	public:
		UIState();
		
		void quitUI() const;
		void setNextPage(UIPage* next) const;

		void runUI(UIPage* page);
	};

}

#endif
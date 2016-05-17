/* Created by: Timmie
*/
#ifndef UISTATE_H
#define UISTATE_H

#include "UIPage.h"
#include"ISystem.h"

namespace ui {

	class UIState
	{
	private:
		/* Constant reference to the system
		*/
		lic::ISystem& sys;

		/* The current page being run
		*/
		UIPage* currentPage;

		/* Mutable represents variables able to change from const functions
		*/

		/* Holds the next page when waiting to finish executing the old function
		*/
		mutable UIPage* nextPage;
		/* Determines if the page should be cleared when switching page.
		*/
		mutable bool _clearPage;
		/* If a call to exit the ui is called.
		*/
		mutable bool quit;

	public:
		UIState(lic::ISystem& sys);
		~UIState();
		
		void quitUI() const;
		/* Set next page
		next << Next page to be displayed
		clearPage << True if the current page should be cleared from console on swap (Default: True)
		*/
		void setNextPage(UIPage* next, bool clearPage = true) const;

		void runUI(UIPage* page);
	};

}

#endif
/* Created by: Timmie
*/
#ifndef UIPAGE_H
#define UIPAGE_H

#include "System.h"

#include <string>

namespace ui {

	/* Forward declaration
	-----------------------
	Declares UIState class existance but the object can not be used in the header.
	Only reference or pointer types can be defined in the header as it has no knowledge of the objects size.
	Forward declaring can be seen as a lazy version of interfaces.

	How to import and use it:
	-------------------------
	The class can then be imported from UIPage.cpp if functions should be used for this object.
	Also every implementation need to import UIState to be able to use it.
	/Mattias
	*/
	class UIState;

	class UIPage
	{
	protected:
		/* Clears input buffer from bad data
		*/
		void clearInputBuffer();
		int getNumberInput(int min, int max);	// gets number between min and max from user

		/* Get a true or false statement ('y'/'n')
		*/
		bool getTrueFalse(); 
		std::string getWordInput();				// gets string from user

		/* The reference to the ui state
		*/
		const UIState& state;
		/* The reference to the system
		*/
		lic::ISystem& sys;
		

	public:
		/* Clears the page by adding line breakers:
		*/
		void clearPage();
		virtual void runPage() = 0;				// implement page code here in inheriting classes

		UIPage(const UIState& state, lic::ISystem& sys);
		virtual ~UIPage();
	};

}
#endif
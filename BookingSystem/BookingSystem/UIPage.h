/* Created by: Timmie
*/
#ifndef UIPAGE_H
#define UIPAGE_H

#include <string>

namespace ui {

	/* Forward declaration
	*/
	class UIState;

	class UIPage
	{
	protected:
		void clearInputBuffer();
		int getNumberInput(int min, int max);	// gets number between min and max from user
		std::string getWordInput();				// gets string from user

		/* The reference to the ui state
		*/
		const UIState& state;

	public:
		virtual void runPage() = 0;				// implement page code here in inheriting classes

		UIPage(const UIState& state);
		~UIPage();
	};

}
#endif
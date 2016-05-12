#ifndef UIPAGE_H
#define UIPAGE_H

#include <string>

class UIPage
{
protected:
	void clearInputBuffer();

public:
	int getNumberInput(int min, int max);	// gets number between min and max from user
	std::string getWordInput();				// gets string from user

	virtual void runPage() = 0;					// implement in inheriting classes

	UIPage();
	~UIPage();
};

#endif
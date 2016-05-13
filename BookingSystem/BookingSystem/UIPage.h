#ifndef UIPAGE_H
#define UIPAGE_H

#include <string>

class UIPage
{
protected:
	void clearInputBuffer();
	int getNumberInput(int min, int max);	// gets number between min and max from user
	std::string getWordInput();				// gets string from user

public:
	virtual void runPage() = 0;				// implement page code here in inheriting classes

	UIPage();
	~UIPage();
};

#endif
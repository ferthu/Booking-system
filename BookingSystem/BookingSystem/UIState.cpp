#include "UIState.h"

void UIState::runUI(UIPage* firstPage)
{
	currentPage = firstPage;
	nextPage = nullptr;
	quit = false;

	currentPage->runPage();

	while (!quit)
	{
		delete currentPage;

		currentPage = nextPage;
		nextPage = nullptr;

		currentPage->runPage();

		if (nextPage == nullptr && !quit)
			throw("No next page selected!");
	}

	delete currentPage;
}

void UIState::setNextPage(UIPage* next)
{
	nextPage = next;
}

void UIState::initialize()
{
	UIState::instance = nullptr;
}

void UIState::cleanup()
{
	delete UIState::instance;
}

UIState* UIState::getInstance()
{
	if (instance == nullptr)
	{
		instance = new UIState();
	}

	return instance;
}

void UIState::quitUI()
{
	quit = true;
}

UIState::UIState() {}
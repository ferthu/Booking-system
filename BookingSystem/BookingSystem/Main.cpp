using namespace std;

#include "UIPage.h"
#include "UIState.h"

#include "TestPages.h"

UIState* UIState::instance;

int main()
{
	UIState::initialize();

	UIState::getInstance()->runUI(new Test1UIPage());

	UIState::cleanup();
}
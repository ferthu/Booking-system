

#include"System.h"
#include"UIState.h"
#include"TestPages.h"
#include<memory>

int main() {

	//Memory leak checks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//There is progress. . . Buffering . . .
	lic::System sys;
	ui::UIState ui;
	
	//Runs the ui
	ui.runUI(new ui::Test1UIPage(ui));
}


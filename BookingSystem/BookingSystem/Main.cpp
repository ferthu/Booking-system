

#include"System.h"
#include"UIState.h"
#include"TestPages.h"
#include<memory>

int main() {

	//Memory leak check:
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//There is progress. . . Buffering . . .

	/* System variables is created on the stack.
	*/
	lic::System sys;
	ui::UIState ui;
	
	//Runs the ui
	ui.runUI(new ui::Test1UIPage(ui));
}


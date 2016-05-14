#include "System.h"
#include "UIState.h"
#include "TestPages.h"
#include "MainUIPage.h"

#include<memory>

int main() {

	//Memory leak check:
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//There is progress. . . Buffering . . .

	/* System variables is created on the stack.
	*/
	lic::System sys;
	ui::UIState ui;

	/* Adds accounts to the system */
	lic::Account acc1 = lic::Account("xX_coolguy_420_Xx", "XD");
	sys.addAccount(acc1);
	
	//Runs the ui
	ui.runUI(new ui::MainUIPage(ui, sys));
}


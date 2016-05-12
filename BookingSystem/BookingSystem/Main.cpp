

#include"System.h"
#include"UIState.h"


int main() {

	//Memory leak checks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//There is progress. . . Buffering . . .
	lic::System sys;
	ui::UIState ui;
	//ui.initialize(...)
}


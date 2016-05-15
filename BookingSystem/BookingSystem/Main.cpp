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

	/* Adds games to library */
	lic::Service game1;
	game1._name = "John's Adventure 7: Redemption";
	game1._description = "In the epic conclusion to the iconic John's Adventure franchise, John regains or gains possession of something in exchange for payment, or clearing a debt.";
	game1._price = 200;
	game1._rating = 0.2f;
	game1._requiredAge = 3;
	game1._tags.push_back("FPS");
	game1.addReview(lic::Review(0, "total piece of shit. wtf ?? ?", "xX_coolguy_420_Xx", lic::Date(2016, 5, 15)));
	sys.getLibrary(lib::RESERVATIONLIBRARY).addService(game1);
	
	//Runs the ui
	ui.runUI(new ui::MainUIPage(ui, sys));
}


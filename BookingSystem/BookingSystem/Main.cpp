#include "System.h"
#include "UIState.h"
#include "TestPages.h"
#include "MainUIPage.h"

#include<memory>

void populateGames(lic::System& sys);
void populateAccounts(lic::System& sys);

int main() {

	//Memory leak check:
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//There is progress. . . Buffering . . .

	/* System variables is created on the stack.
	*/
	lic::System sys;
	ui::UIState ui(sys);

	populateAccounts(sys);
	populateGames(sys);

	
	//Runs the ui
	ui.runUI(new ui::MainUIPage(ui, sys));
}

void populateAccounts(lic::System& sys) {
	/* Adds accounts to the system */
	lic::Account acc = lic::Account("xX_coolguy_420_Xx", "XD");
	sys.addAccount(acc);
	acc = lic::Account("name", "password");
	sys.addAccount(acc);
}

void populateGames(lic::System& sys) {
	/* Adds games to library */
	lic::ILibrary& gameLib = sys.getLibrary(lib::GAMELIBRARY);
	lic::ILibrary& mentorLib = sys.getLibrary(lib::MENTORLIBRARY);

	lic::Service game;
	game._name = "John's Adventure 7: Redemption";
	game._description = "In the epic conclusion to the iconic John's Adventure franchise, John regains or gains possession of something in exchange for payment, or clearing a debt.";
	game._price = 350;
	game._rating = 0.2f;
	game._requiredAge = 3;
	game._tags.push_back("FPS");
	game.addReview(lic::Review(0, "total piece of shit. wtf ?? ?", "xX_coolguy_420_Xx", lic::Date(2016, 5, 15)));
	gameLib.addService(game);

	game._name = "Mentor";
	game._description = "Mentor is available to book with games.";
	game._price = 1600;
	game._rating = 0.2f;
	game._requiredAge = 3;
	game._tags.push_back("OPTIONAL");
	mentorLib.addService(game);
}


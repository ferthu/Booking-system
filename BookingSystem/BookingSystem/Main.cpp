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
	game._rating = 0;
	game._requiredAge = 3;
	game._tags.push_back("FPS");
	game.addReview(lic::Review(0, "total piece of shit. wtf ?? ?", "xX_coolguy_420_Xx", lic::Date(2016, 5, 15)));
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Hotline Miami";
	game._description = "Top down shooter with stealth, extreme violence and surreal storytelling, along with a soundtrack and visuals influenced by 1980s culture.";
	game._price = 570;
	game._requiredAge = 18;
	game._tags.push_back("top down");
	game._tags.push_back("shooter");
	game._tags.push_back("pixel");
	game._tags.push_back("bloody");
	game._tags.push_back("action");
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Oniken";
	game._description = "Retro side-scrolling action platformer.";
	game._price = 230;
	game._rating = 2.5;
	game._requiredAge = 7;
	game._tags.push_back("platform");
	game._tags.push_back("action");
	game._tags.push_back("pixel");
	game._tags.push_back("NES");
	game.addReview(lic::Review(5, "Best game ever!! #Huge#SoMuchWin#Greatest", "name", lic::Date(2016, 5, 11)));
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Stronghold";
	game._description = "Medieval real time strategy game with resource management.";
	game._price = 330;
	game._requiredAge = 7;
	game._tags.push_back("RTS");
	game._tags.push_back("strategy");
	game._tags.push_back("medieval");
	game._tags.push_back("classic");
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Alice: Madness Returns";
	game._description = "Surrealistic action platformer in a tird person perpective.";
	game._price = 890;
	game._requiredAge = 17;
	game._tags.push_back("platform");
	game._tags.push_back("action");
	game._tags.push_back("surrealistic");
	game._tags.push_back("colorful");
	game._tags.push_back("bloody");
	game._tags.push_back("story");
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Super Smash Bros: Melee";
	game._description = "Action platform brawler with classic nintendo characters.";
	game._price = 890;
	game._requiredAge = 7;
	game._tags.push_back("multiplayer");
	game._tags.push_back("mario");
	game._tags.push_back("nintendo");
	game._tags.push_back("brawler");
	game._tags.push_back("fighting");
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Witcher 3";
	game._description = "Large open world RPG with in a fantasy world based on the witcher book series.";
	game._price = 1190;
	game._requiredAge = 7;
	game._tags.push_back("story");
	game._tags.push_back("RPG");
	game._tags.push_back("fantasy");
	game._tags.push_back("action");
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Heroes of might and magic 3";
	game._description = "A turn based strategy game with rpg elements and a randomly generated world.";
	game._price = 590;
	game._requiredAge = 7;
	game._tags.push_back("strategy");
	game._tags.push_back("turn based");
	game._tags.push_back("RPG");
	game._tags.push_back("fantasy");
	game._tags.push_back("classic");
	gameLib.addService(game);
	game._tags.clear();

	game._name = "Brutal DOOM";
	game._description = "A mod for the classic FPS game DOOM. Improved controls and visuals!";
	game._price = 390;
	game._requiredAge = 7;
	game._tags.push_back("FPS");
	game._tags.push_back("bloody");
	game._tags.push_back("action");
	game._tags.push_back("demons");
	game._tags.push_back("mod");
	gameLib.addService(game);
	game._tags.clear();
	//----
	game._name = "Mentor";
	game._description = "Mentor is available to book with games.";
	game._price = 1600;
	game._rating = 0.2f;
	game._requiredAge = 3;
	game._tags.push_back("OPTIONAL");
	mentorLib.addService(game);
}


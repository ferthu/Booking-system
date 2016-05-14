#include "MainUIPage.h"
#include "LoginUIPage.h"

void ui::LoginUIPage::tryLogin(std::string& username, std::string& password)
{
	std::cout << "Enter username or 'back' to go back: ";
	username = getWordInput();

	if (username != "back")
	{
		std::cout << "Enter password: ";
		password = getWordInput();
	}
}

void ui::LoginUIPage::runPage()
{
	std::cout << "Booking System\n\n";
	std::cout << "Log in\n";

	if (sys.getAccount() == nullptr)
	{
		bool success = false;
		std::string username;
		std::string password;

		tryLogin(username, password);

		while (username != "back" && !(success = sys.login(username, password))) {
			std::cout << "Unrecognized username or password.\n\n";

			tryLogin(username, password);
		}

		if (username != "back")
		{
			std::cout << "Logged in as " << username << ".";
			getchar();
		}
	}
	else
	{
		std::cout << "\nAlready signed in as " << sys.getAccount()->getName() << ".";
		getchar();
	}

	state.setNextPage(new ui::MainUIPage(state, sys));
}
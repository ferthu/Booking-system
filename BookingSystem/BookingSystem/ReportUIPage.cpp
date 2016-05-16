#include "ReportUIPage.h"
#include "MainUIPage.h"
#include "ReservationCalendar.h"
#include "Reservation.h"

void ui::ReportUIPage::runPage()
{
	std::cout << "Reservations:\n";
	lic::Reservation r;

	for (int i = 0; i < sys.getAccounts().size(); i++)
	{
		std::string accountName = sys.getAccounts()[i].getProfile()[0];
		std::shared_ptr<std::vector<lic::Reservation>> reservations = sys.getCalendar().getReservations(accountName);
		int size = reservations->size();
		if (size > 0) {
			std::cout << accountName << std::endl;
			for (int j = 0; j < (sys.getCalendar().getReservations(accountName))->size(); j++) {
				r = sys.getCalendar().getReservations(sys.getAccounts()[i].getProfile()[0])->operator[](j);
				std::cout << "Game: ";
				for (int k = 0; k < r._services.size(); k++) {
					std::cout << r._services[k]._name << ",";
				}
				std::cout << "\nDate: " << r._date._day << "/" << r._date._month << "/" << r._date._year;
				std::cout << "\nTime: " << r._time._hour << ":" << r._time._minute;
				std::cout << "\nPlayers: " << r._players;
				if (r._paid)
					std::cout << "\nService paid";
				else
					std::cout << "\nService not yet paid";
				std::cout << "\n\n";
			}
		}
	}
	std::cout << "Press '0' to go back";
	int selection = getNumberInput(0, 0);
	if (selection == 0)
		state.setNextPage(new ui::MainUIPage(state, sys));
}
#include"Reservation.h"

namespace lic {


	Reservation::Reservation() {}
	Reservation::Reservation(Date date, int players, const std::vector<std::string>& services)
		: _date(date), _players(players), _services(services) {	}

	Reservation::Reservation(const std::vector<std::string>& services)
	: _services(services) {
	}


	/* Comparison operator
	*/
	bool Reservation::operator==(const Reservation& other) const {
		//Compare service lists
		if (other._services.size() != this->_services.size())
			return false;
		for (unsigned int i = 0; i < other._services.size(); i++)
			if (other._services[i] != this->_services[i])
				return false;
		//Compare variables
		return _date == other._date && _time == other._time && _accountName == other._accountName;
	}
}
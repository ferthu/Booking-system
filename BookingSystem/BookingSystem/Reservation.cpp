#include"Reservation.h"

namespace lic {


	Reservation::Reservation() {}
	Reservation::Reservation(Date date, int players, const std::vector<std::string>& services)
		: _services(services), _date(date), _players(players),  _time(), _accountName(""), _paid(false) {	}

	Reservation::Reservation(Date date, int players, const std::string& service)
		: _date(date), _players(players), _time(), _accountName(""), _paid(false)
	{
		_services.push_back(service);
	}

	Reservation::Reservation(const std::vector<std::string>& services)
	: _services(services), _date(), _players(1), _time(), _accountName(""), _paid(false) {
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
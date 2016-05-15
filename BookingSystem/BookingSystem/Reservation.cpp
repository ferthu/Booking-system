#include"Reservation.h"
#include"SystemLibraries.h"

namespace lic {


	Reservation::Reservation() {}
	Reservation::Reservation(Date date, int players, const std::vector<ServiceType>& services)
		: _services(services), _date(date), _players(players),  _time(), _accountName(""), _paid(false) {	}

	Reservation::Reservation(Date date, int players, const std::string& service, const std::string& service_type)
		: Reservation(date, players, ServiceType(service, service_type))
	{
	}
	Reservation::Reservation(Date date, int players, const ServiceType service)
		: _date(date), _players(players), _time(), _accountName(""), _paid(false)
	{
		_services.push_back(service);
	}

	Reservation::Reservation(const std::vector<ServiceType>& services)
	: _services(services), _date(), _players(1), _time(), _accountName(""), _paid(false) {
	}

	/*
	*/
	int Reservation::getReservationCount(unsigned int index) const{
		if (_services.size() <= index)
			return 0;

		if (_services[index]._type == lib::MENTORLIBRARY)
			return 1;
		else if (_services[index]._type == lib::GAMELIBRARY)
			return _players;
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
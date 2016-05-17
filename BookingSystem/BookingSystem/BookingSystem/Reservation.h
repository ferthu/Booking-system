#pragma once

#include<string>
#include<vector>
#include"Date.h"
#include"Time.h"
#include"ServiceType.h"


namespace lic {
	/* Information about a reservation added to the system.
	*/
	class Reservation {
	public:
		/* Reservation date
		*/
		Date _date;
		/* Reservated time slot
		*/
		Time _time;
		/* Number of players reserved for
		*/
		int _players;
		/* If the reservation is paid or not.
		*/
		bool _paid;
		/* Name of the account that reserved.
		*/
		std::string _accountName;
		/* Services reserved
		*/
		std::vector<ServiceType> _services;

		Reservation();
		Reservation(Date date, int players, const std::vector<ServiceType>& services);
		Reservation(Date date, int players, const std::string& service, const std::string& service_type);
		Reservation(Date date, int players, const ServiceType service);
		Reservation(const std::vector<ServiceType>& services);

		/* Get how reservations of a type reserved
		*/
		int getReservationCount(unsigned int index) const;

		/* Comparison operator
		*/
		bool operator==(const Reservation& other) const;

	};

}
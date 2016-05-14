#pragma once

#include<string>
#include<vector>
#include"Date.h"
#include"Time.h"



namespace lic {
	/* Information about a reservation added to the system.
	*/
	class Reservation {
	public:
		/* Reservation date
		*/
		Date _date;
		/* Reservated time
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
		std::vector<std::string> _services;

		Reservation();
		Reservation(Date date, int players, const std::vector<std::string>& services);
		/* Comparison operator
		*/
		bool operator==(const Reservation& other) const;

	};

}
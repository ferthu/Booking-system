#pragma once

#include"Reservation.h"
#include<vector>

namespace lic {

	/* Account interface. Represents a user in the system.
	*/
	class IAccount
	{
	public:
		virtual ~IAccount() {};

		/* Fetches the reservations reserved by the account.
		*/
		virtual std::vector<Reservation>& getReservations() = 0;
		/* Get the profile as a set of strings ?...
		*/
		virtual std::vector<std::string>& getProfile() = 0;
		/* Set the profile as a set of strings ?...
		*/
		virtual std::vector<std::string>& editProfile() = 0;
		/* Get the access level of the account
		*/
		virtual int getAccessLevel() = 0;
	};
}


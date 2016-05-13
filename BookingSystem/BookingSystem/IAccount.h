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

		/* Get the profile as a set of strings ?...
		*/
		virtual std::vector<std::string>& getProfile() = 0;
		/* Set the profile as a set of strings ?...
		*/
		virtual std::vector<std::string>& editProfile() = 0;
		/* Access account name. Used to link system elements with the account.
		*/
		virtual std::string& getName() = 0;
		/* Get the access level of the account
		*/
		virtual int getAccessLevel() = 0;
	};
}


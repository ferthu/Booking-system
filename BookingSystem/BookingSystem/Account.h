#pragma once

#include "Reservation.h"
#include "IAccount.h"
#include <vector>

namespace lic {

	/*	Account interface. Represents a user in the system.

		A profile is represented as a vector with two strings, profile[0] holds user name, profile[1] holds password.
	*/
	class Account : public IAccount
	{
	private:
		std::string name;
		std::string password;

	public:
		virtual ~Account() {};

		/* Get the profile as a set of strings ?...
		*/
		virtual std::vector<std::string>& getProfile();
		/* Set the profile as a set of strings ?...
		*/
		virtual void editProfile(std::vector<std::string>& profile);
		/* Access account name. Used to link system elements with the account.
		*/
		virtual std::string& getName();
		/* Get the access level of the account
		*/
		/*virtual int getAccessLevel();*/
	};
}


// Written by Timmie

#include "Account.h"

lic::Account::Account(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
}

std::vector<std::string> lic::Account::getProfile()
{
	std::vector<std::string> profile;

	profile.push_back(name);
	profile.push_back(password);

	return profile;
}

void lic::Account::editProfile(std::vector<std::string>& profile)
{
	name = profile[0];
	password = profile[1];
}

std::string& lic::Account::getName()
{
	return name;
}
#pragma once

#include<string>

/* Defines a type of service
*/
struct ServiceType {
	std::string _name, _type;

	ServiceType() 
	: _name(""), _type(""){}
	ServiceType(const std::string& name, const std::string& type)
		: _name(name), _type(type) {}


	bool operator==(const ServiceType& other) const {
		return other._name == _name && other._type == _type;
	}
	bool operator!=(const ServiceType& other) const {
		return other._name != _name || other._type != _type;
	}
};
#include "Library.h"


namespace lic {

	Library::Library(const std::string& name)
		: _name(name)
	{
	}


	Library::~Library()
	{
	}


	/* Get services in the library filtered with the specified filter.
	*/
	std::shared_ptr<std::vector<Service>> Library::getServices(const Filter& f) {
		std::shared_ptr<std::vector<Service>> services(new std::vector<Service>());
		return services;
	}

	/* Get service with the specific name.
	name	<<	Name of the service
	service	>>	Returns the service by reference (if it exists).
	return	>>	Returns if a service with the specified name exists
	*/
	bool Library::getService(const std::string& name, Service& service){
		std::map<std::string, Service>::iterator it = _library.find(name);
		if (it != _library.end()) {
			service = it->second;
			return true;
		}
		return false;
	}

	/* Add the service to the library
	*/
	void Library::addService(const Service& service) {

	}
}

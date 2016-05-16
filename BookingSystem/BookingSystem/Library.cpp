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


		//Loop over the map and add to the list
		for (std::map<std::string, Service>::iterator it = _library.begin(); it != _library.end(); ++it) {
			if (it->second._name.find(f._text) == std::string::npos &&
				it->second._description.find(f._text) == std::string::npos) {
				continue;
			}
			if (it->second._price._amount > f._maxPrice) {
				continue;
			}
			if (it->second._rating <= f._rating) {
				//continue;
			}
			if (it->second._requiredAge > f._ageRestriction) {
				continue;
			}
			bool found = false;
			if (f._tags.size() > 0) {
				if (it->second._tags.size() > 0) {
					for (int i = 0; i < it->second._tags.size(); i++) {
						for (int j = 0; j < f._tags.size(); j++) {
							if (it->second._tags[i].compare(f._tags[j]) ==0)
							{
								found = true;
								i = it->second._tags.size();
							}
						}
					}
				}
			}
			else {
				found = true;
			}
			if (!found) {
				continue;
			}
			
			services->push_back(it->second);
		}

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
		//Add or overwrite existing slot:
		_library[service._name] = service;
	}
}

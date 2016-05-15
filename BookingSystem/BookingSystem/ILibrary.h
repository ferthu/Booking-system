#pragma once

#include<string>
#include<vector>
#include"Service.h"
#include"Filter.h"
#include<memory>
#include"SystemLibraries.h"

namespace lic {

	/* Library interface. Library holds the services/products that are available in the system.
	It can be queried to gain access to services.
	*/
	class ILibrary {
	public:
		
		/* Get services in the library filtered with the specified filter.
		*/
		virtual std::shared_ptr<std::vector<const Service&>> getServices(const Filter& f) = 0;

		/* Get service with the specific name.
		name	<<	Name of the service
		service	>>	Returns the service by reference (if it exists).
		return	>>	Returns if a service with the specified name exists
		*/
		virtual bool getService(const std::string& name, Service& service) = 0;

		/* Add the service to the library
		*/
		virtual void addService(const Service& service) = 0;

		virtual ~ILibrary() {};

	};

}
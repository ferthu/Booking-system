#pragma once
#include "ILibrary.h"
#include<map>

namespace lic {

	class Library :
		public ILibrary
	{

		std::map<std::string, Service> _library;

	public:

		const std::string _name;

		Library(const std::string& name);
		virtual ~Library();


		/* Get services in the library filtered with the specified filter.
		*/
		virtual std::shared_ptr<std::vector<const Service&>> getServices(const Filter& f);

		/* Get service with the specific name.
		name	<<	Name of the service
		service	>>	Returns the service by reference (if it exists).
		return	>>	Returns if a service with the specified name exists
		*/
		virtual bool getService(const std::string& name, Service& service);

		/* Add the service to the library
		*/
		virtual void addService(const Service& service);
	};

}


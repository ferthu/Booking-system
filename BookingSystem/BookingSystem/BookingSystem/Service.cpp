#include "Service.h"

namespace lic {

	Service::Service()
	{
	}

	Service::~Service()
	{
	}
	/* Add a review to the service
	*/
	void Service::addReview(Review& review) {
		_reviews.push_back(review);
	}
	/* Copy the information to the service.
	*/
	void Service::updateInformation(Service& service) {
		//Todo
	}

}

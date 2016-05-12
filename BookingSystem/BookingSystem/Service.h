#pragma once

#include"Review.h"
#include<string>
#include<vector>

namespace lic {


	/* Base object for the services offered in the system
	*/
	class Service
	{
	private:
		/* Service/ product name*/
		std::string _name;
		/* Text describing the service*/
		std::string _description;
		/* Product price*/
		int _price;
		/* Average rating*/
		float _rating;
		/* Minimum age to buy the service*/
		int _requiredAge;
		/* Tags related to the service	*/
		std::vector<std::string> _tags;
		/* Reviews written of the service*/
		std::vector<Review> _reviews;

	public:
		Service();
		~Service();
		/* Add a review to the service
		*/
		void addReview(Review& review);
		/* Copy the information to the service.
		*/
		void updateInformation(Service& service);
	};

}

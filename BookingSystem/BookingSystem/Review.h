#pragma once

#include<string>
#include"IAccount.h"
#include"Date.h"

namespace lic {

	/* Object holding information related to a review of a product/service offered in the system.
	*/
	class Review {
		/* Rating from the review
		*/
		int _rating;
		/* Comment of the product
		*/
		std::string _review;
		/* The name of the account that created the review.
		*/
		std::string _account;
		/* The date the review was written.
		*/
		Date _date;


		Review() {}

		Review(int rating,std::string review, std::string account, Date date) 
		: _rating(rating), _review(review), _account(account), _date(date){}

	};

}
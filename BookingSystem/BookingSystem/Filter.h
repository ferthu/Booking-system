#pragma once

#include<string>
#include<vector>

namespace lic {

	/* Struct representing a filter, used to filter service objects.
	*/
	class Filter {
	public:
		/* String the name of the game must contain
		*/
		std::string _text;
		/* Minimum rating of the service
		*/
		int _rating;
		/* Maximum age limit of the games/services.
		*/
		int _ageRestriction;
		/* Maximum price, sort away all above it.
		*/
		int _maxPrice;
		/* Tags that must be related to the service.
		*/
		std::vector<std::string> _tags;
		
		Filter()
			: _text(""), _rating(0), _ageRestriction(99), _maxPrice(100000), _tags() {}

	};
}


#include<iostream>
#include "ViewReviewsUIPage.h"
#include "GameDescriptionUIPage.h"
#include"DisplayReservationFunc.h"
namespace ui {

	ViewReviewsUIPage::ViewReviewsUIPage(const UIState& state, lic::ISystem& sys, const lic::Service service)
		: UIPage(state, sys), _service(service)
	{
	}


	ViewReviewsUIPage::~ViewReviewsUIPage()
	{
	}

	void ViewReviewsUIPage::runPage()
	{
		std::cout << "Reviews for " << _service._name << "\n\n";

		for (int i = 0; i < _service._reviews.size(); i++) {
			std::cout << "Rating: " << _service._reviews[i]._rating << std::endl;
			std::cout << "Comment: " << _service._reviews[i]._review << std::endl;
			std::cout << "Written by: " << _service._reviews[i]._account << std::endl;
			std::cout << "Date: ";
			displayDate(_service._reviews[i]._date);
			std::cout << std::endl << std::endl;
		}

		std::cout << "\n\n0. To go Back:";
		int selection = getNumberInput(0, 0);
		lic::Filter f;
		if (selection == 0)
		{
			state.setNextPage(new GameDescriptionUIPage(state, sys, _service));
		}
	}

}
#pragma once
#include "UIPage.h"

namespace ui {

	/* Page viewing the reviews for a service. Accessible through GameDescription page.
	*/
	class ViewReviewsUIPage :
		public UIPage
	{
	private:
		lic::Service _service;
	public:
		ViewReviewsUIPage(const UIState& state, lic::ISystem& sys, const lic::Service service);
		virtual ~ViewReviewsUIPage();
		virtual void runPage();
	};

}


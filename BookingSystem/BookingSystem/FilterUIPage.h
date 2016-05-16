#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui
{
	class FilterUIPage : public UIPage
	{
	private:
		lic::Filter _filter;
	public:
		FilterUIPage(const UIState& state, lic::ISystem& sys, const lic::Filter filter);
		virtual ~FilterUIPage() {}

		void runPage();
	};
}
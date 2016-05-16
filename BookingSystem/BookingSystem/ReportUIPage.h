#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui
{
	class ReportUIPage : public UIPage
	{
	public:
		ReportUIPage(const UIState& state, lic::ISystem& sys)
			: UIPage(state, sys) {}
		virtual ~ReportUIPage() {}

		void runPage();
	};
}
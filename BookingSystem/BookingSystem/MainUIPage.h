// Created by Timmie

#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui 
{
	class MainUIPage : public UIPage
	{
	public:
		MainUIPage(const UIState& state, lic::System& sys)
			: UIPage(state, sys) {}

		void runPage();
	};
}
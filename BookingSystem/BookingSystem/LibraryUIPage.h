// Created by Timmie

#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui
{
	class LibraryUIPage : public UIPage
	{
	public:
		LibraryUIPage(const UIState& state, lic::ISystem& sys)
			: UIPage(state, sys) {}

		virtual ~LibraryUIPage(){}

		void runPage();
	};
}
// Created by Timmie

#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui
{
	class LibraryUIPage : public UIPage
	{
	private:
		lic::Filter _filter;
	public:
		LibraryUIPage(const UIState& state, lic::ISystem& sys, const lic::Filter filter);
		virtual ~LibraryUIPage(){}

		void runPage();
	};
}
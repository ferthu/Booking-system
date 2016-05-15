// Created by Timmie

#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui
{
	class GameDescriptionUIPage : public UIPage
	{
	private:
		lic::Service _service;

	public:
		GameDescriptionUIPage(const UIState& state, lic::ISystem& sys, const lic::Service service);
		virtual ~GameDescriptionUIPage() {}

		void runPage();
	};
}
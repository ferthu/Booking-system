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
		const lic::Service& _service;

	public:
		GameDescriptionUIPage(const UIState& state, lic::System& sys, const lic::Service& service)
			: UIPage(state, sys), _service(service) {}

		void runPage();
	};
}
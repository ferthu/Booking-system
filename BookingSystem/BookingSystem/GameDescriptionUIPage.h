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
		// the selected game

	public:
		GameDescriptionUIPage(const UIState& state, lic::System& sys /*, also takes a game as a parameter */)
			: UIPage(state, sys) {}

		void runPage();
	};
}
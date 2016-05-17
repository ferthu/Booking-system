// Created by Timmie

#pragma once

#include <iostream>

#include "UIPage.h"
#include "UIState.h"

namespace ui
{
	class LoginUIPage : public UIPage
	{
	private:
		// help function
		void tryLogin(std::string& username, std::string& password);
	public:
		LoginUIPage(const UIState& state, lic::ISystem& sys)
			: UIPage(state, sys) {}
		virtual ~LoginUIPage() {}

		void runPage();
	};
}
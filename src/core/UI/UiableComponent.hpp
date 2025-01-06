#pragma once

#include "../UI/UiPanel.hpp"
#include "../../core/Component.hpp"
namespace ltn {
	class UiableComponent : virtual public UiPanel, virtual public Component
	{
	public:
		bool m_activate = true;
		virtual void init_ui_content() {};

	};
}
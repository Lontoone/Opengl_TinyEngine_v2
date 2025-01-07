#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <functional>
#include "UiItem.hpp"

namespace ltn {

	class UiPanel
	{
	public:
		//UiPanel(uint32_t* cmp_id);
		//~UiPanel();
		const char* m_target_comp_id;
		typedef std::function<bool()> t_draw_cmd;
		::std::vector<t_draw_cmd> m_draw_cmds;
		//void add_draw_item(t_draw_cmd& _draw_cmd);

		void add_draw_item(std::function<bool()> _draw_cmd);
		void add_drop_down_menu(::std::vector<::std::string>& _ops, void(*func)(::std::string)){};
		void draw_ui_panel();
		void create_panel(const char* window_name);
		void panel_begin();
		void panel_end();

		//void add_item(UiItem * item);

		::std::vector<UiItem*> m_items;
		const char* m_panel_names = "Default window";
		

	private:
		//std::string generate_random_id(size_t length);
	};
}

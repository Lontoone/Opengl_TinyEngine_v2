#include "UiPanel.hpp"

void ltn::UiPanel::add_draw_item(std::function<bool()> _draw_cmd)
{
	this->m_draw_cmds.push_back(_draw_cmd);
}

void ltn::UiPanel::draw_ui_panel()
{
	ImGui::Text("1234");
	
	for (auto _cmd : this->m_draw_cmds) {
		//_item->run_all_draw_cmd();
		_cmd();
	}
}

void ltn::UiPanel::create_panel(const char* window_name)
{
	this->m_panel_names = window_name;
}

void ltn::UiPanel::panel_begin()
{
	if (this->m_panel_names == "") {
		this->m_panel_names = "No Name";
	}
	ImGui::SetNextWindowPos(ImGui::GetMainViewport()->Pos);
	ImGui::Begin(this->m_panel_names);
}

void ltn::UiPanel::panel_end()
{
	ImGui::End();
}

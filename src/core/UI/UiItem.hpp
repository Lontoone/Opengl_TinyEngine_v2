#pragma once
namespace ltn{
#include <vector>
#include <functional>
class UiItem
{
public:
	//UiItem();
	//~UiItem();
	

	typedef ::std::function<void()> t_draw_cmd;
	::std::vector<t_draw_cmd> m_draw_cmds;

	virtual void init_ui_item() {};
	void add_draw_item(t_draw_cmd& _draw_cmd);
	void run_all_draw_cmd();

private:
	
};
}

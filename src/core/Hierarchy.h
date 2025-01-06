#pragma once
#include <map>
//#include "Flags.h"
//#include "UI/UiPanel.hpp"
#include <string>
#include <vector>
#include "GameObject.hpp"
//#include "Ltn.h"
namespace ltn{


class Hierarchy //: public UiPanel
{
public:
	static Hierarchy& instance() {
		return sInstance;
	}

	//void execute(EXECUTE_TIMING timimg);
	void draw_ui_loop();		
	void add_object(GameObject* new_obj);

	::std::vector<::std::string>* get_gameobjs_list();
	GameObject* get_gameobjs_by_name(::std::string name);

	::std::vector<GameObject*> m_game_objects;
	

private:	
	Hierarchy() {};
	static Hierarchy sInstance ;
	
	//vector<ExecuteList*> m_execute_layers;
	//Camera* m_main_camera;
	::std::map<::std::string, GameObject*> m_gameobj_maps;
	//vector<string> m_gameobject_names;
	void update_shadow_maps();
	void do_before_frame();
	void do_after_frame();
	void do_frame();	
};

}
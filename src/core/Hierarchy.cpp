#include "Hierarchy.h"
ltn::Hierarchy ltn::Hierarchy::sInstance; // Define the static member
void ltn::Hierarchy::draw_ui_loop()
{	
	
	for (int i = 0; i < this->sInstance.m_game_objects.size(); i++) {		
		this->sInstance.m_game_objects[i]->update_ui_tree();
	}
}

void ltn::Hierarchy::add_object(GameObject* new_obj){
	
	this->sInstance.m_game_objects.push_back(new_obj);
	//sInstance.m_gameobject_names.push_back(new_obj->name);
	//sInstance.m_gameobj_maps[new_obj->name ]= new_obj;
}

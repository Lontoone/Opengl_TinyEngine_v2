#include "GameObject.hpp"
ltn::GameObject::GameObject(const char* _obj_name)
{
	this->name = _obj_name;
	this->m_components_panels;
}
void ltn::GameObject::update_ui_tree(){
	//panel_begin();	
	
	for (int i = 0; i < this->m_components_panels.size(); i++) {		
		this->m_components_panels[i]->draw_ui_panel();		
	}
	
}
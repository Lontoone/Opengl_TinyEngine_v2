#include "GameObject.hpp"
ltn::GameObject::GameObject()
{
	this->name = "no name object";
	// Create transformobject
	this->transform = std::make_unique<TransformObject>();
	this->add_component(this->transform.get());
	
}
ltn::GameObject::GameObject(const char* _obj_name)
{
	GameObject();
	this->name = _obj_name;
	this->m_components_panels;
}
void ltn::GameObject::update_ui_tree(){
	
	for (int i = 0; i < this->m_components_panels.size(); i++) {		
		this->m_components_panels[i]->draw_ui_panel();		
	}
	
}

void ltn::GameObject::add_component(Component* _new_comp)
{
	this->m_comps.push_back(_new_comp);
	_new_comp->attatch_to(this);

	UiPanel* have_ui = dynamic_cast<UiPanel*>(_new_comp);
	if (have_ui != nullptr) {
		this->m_components_panels.push_back(have_ui);
	}
}

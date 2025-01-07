#pragma once
#include "Component.hpp"
#include <string>
#include <vector>
#include "Flags.h"
#include <map>
//#include "UI/UiableComponent.hpp"
#include "TransformObject.h"
#include "UI/UiPanel.hpp"

namespace ltn{
class GameObject : public Component //, public UiPanel
{
public:
	GameObject();	
	GameObject(const char* _obj_name);
	~GameObject(){};
		
	const char* name ="";
	std::unique_ptr<TransformObject> transform = nullptr;
	//::std::string name="";
	const char* m_instance_id="";
	//int32 m_instance_id =0;

	::std::vector<Component*>		m_comps;
	::std::vector<GameObject*>		m_childs;
	
	//TransformObject*				m_transform;	

	void execute(EXECUTE_TIMING timimg);
	void update_ui_tree();

	//void set_name(const char* new_name);	
	template<class T> void add_component(T* _new_comp) {
		this->m_components_type[typeid(T).name()] = (Component*)_new_comp;
		this->add_component((Component*)_new_comp);
	};
	void add_component(Component* _new_comp );		
	//void add_component(UiableComponent* _new_comp);	
	void replace_component(int idx , Component* ptr);
	
	//void DO_Before_Frame() override;
	//void Do_End_Frame() override;

	bool add_child(GameObject* _child);
	void remove_child(GameObject* _child);
	bool check_is_child(GameObject* _child);
	//Component* copy()override;
	::std::vector<GameObject*> clone();

	template<class T>
	T* get_component() {
		
		//return (T*)this;
		return dynamic_cast<T*>(this->m_components_type[typeid(T).name()]);

		
	}
private:	
	::std::vector<UiPanel*>			m_components_panels;
	::std::map <::std::string , Component*>	m_components_type;

};
	
}
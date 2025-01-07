#pragma once
#include "UI/UiableComponent.hpp"

//#include <glm/glm.hpp>

namespace ltn{
class TransformObject :public ltn::UiableComponent 
{
public:
	TransformObject();

	TransformObject* m_parent=nullptr;
	void init_ui_content() override;
	
};
}
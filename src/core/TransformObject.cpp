#include "TransformObject.h"

ltn::TransformObject::TransformObject()
{
	init_ui_content();
}

void ltn::TransformObject::init_ui_content()
{
	auto title_text = [&]() {ImGui::Text("========= [ Transform ] ============"); return true; };
	this->add_draw_item(title_text);
}

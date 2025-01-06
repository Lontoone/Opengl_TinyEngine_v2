#include "UiManager.h"

void recursive_add_node(const char* _name, ltn::GameObject* current, std::vector<ltn::GameObject*>& _nexts, int n)
{
	//PushID(_id);
	ImGui::PushID(_name);
	bool tree_node_open = ImGui::TreeNodeEx(
		_name,
		ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_FramePadding |
		ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth
	);

	if (tree_node_open) {
		current->update_ui_tree();
		for (auto _nextPanel : _nexts) {
			recursive_add_node(_nextPanel->name, _nextPanel, _nextPanel->m_childs, n + 1);

		}
		/*  [Demo Dragging]
		//ImGui::Selectable(current->name);
		if (ImGui::IsItemActive() && !ImGui::IsItemHovered())
		{
			int n_next = n + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
			if (n_next >= 0 && n_next < 3)
			{
				ImGui::ResetMouseDragDelta();
			}
		}
		*/
		ImGui::TreePop();
	}
	ImGui::PopID();
}
void ltn::UiManager::create_hierarchy_window(::std::vector<GameObject*>& objs)
{

	const ImGuiViewport* viewport = ImGui::GetMainViewport();

	ImGui::SetNextWindowPos(viewport->WorkPos);

	ImGui::Begin("Object List");

	int  i = 0;
	for (auto& obj : objs) {
		//if (obj->m_transform->m_parent == nullptr) 
		{
			recursive_add_node(obj->name, obj, obj->m_childs, i);
			i++;
		}
	}
	ImGui::End();

}

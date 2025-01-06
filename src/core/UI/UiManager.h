#pragma once
#include "../Ltn.h"
#include <vector>
namespace ltn{
	class UiManager {
	public:
		void create_hierarchy_window(::std::vector<GameObject*>& objs);
	};
}
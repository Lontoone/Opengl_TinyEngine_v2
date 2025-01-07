#include "Component.hpp"

void ltn::Component::attatch_to(Component* ptr)
{
	this->gameobject = ptr;
}

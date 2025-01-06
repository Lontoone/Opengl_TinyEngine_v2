#pragma once
namespace ltn {

	class Component
	{
	public:
		Component(){};		
		virtual ~Component(){};

		int execute_order = 3;
		//const char* name = "";
		virtual inline const char* get_cmp_name(){return "";};
		unsigned int  comp_id;


		Component* gameobject;
		virtual void Do() {};
		virtual void DO_Before_Frame() {};
		virtual void Do_End_Frame() {};
		//GameObject* get_gameobject() { return (GameObject*)this->m_gameobject; };

		virtual Component* copy() { return nullptr; };
		virtual void bind_uniform(unsigned int shader_pid) {};

		void attatch_to(Component* ptr);

		template<class T>
		T* cast_component() {			
			return (T*)this;
		}
		

	};

}
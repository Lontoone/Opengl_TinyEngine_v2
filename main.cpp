#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/mat4x2.hpp>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main() {

	GLFWwindow* window;
	const unsigned int SCR_WIDTH = 480;
	const unsigned int SCR_HEIGHT = 480;
	// Init window
	glfwInit();	
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);	


	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "test window", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

	// Setup Platform/Renderer backends		
	ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
	ImGui_ImplOpenGL3_Init("#version 330");

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	while (!glfwWindowShouldClose(window)) 
	{		
		glfwPollEvents();		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("hi");
		ImGui::Text("hi2");
		ImGui::End();

		ImGui::Begin("hi2");
		ImGui::Text("hi22");
		ImGui::End();

		ImGui::BeginMainMenuBar();
		ImGui::Text("hi33");
		ImGui::EndMainMenuBar();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		
		// Rendering
        ImGui::Render();
        glClearColor(0, 0, 0, 1.0f);		
		glEnable(GL_DEPTH_TEST);		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
	}
}
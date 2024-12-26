cmake_minimum_required(VERSION 3.14)
project(TinyEngine_v2)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
# Add your executable
add_executable(${PROJECT_NAME} main.cpp)


# Include the FetchContent module
include(FetchContent)
#==========================
#		Opengl
#==========================
find_package(OpenGL REQUIRED)

#==========================
#		GLFW
#==========================
# Define GLFW dependency
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)
# Make GLFW available
FetchContent_MakeAvailable(glfw)

#==========================
#		Imgui
#==========================
FetchContent_Declare(imgui
    GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
    GIT_TAG "v1.91.0-docking"
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(imgui)
target_sources(${PROJECT_NAME} PRIVATE
    "${imgui_SOURCE_DIR}/imgui.cpp"
    "${imgui_SOURCE_DIR}/imgui_draw.cpp"
    "${imgui_SOURCE_DIR}/imgui_tables.cpp"
    "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
	)
target_include_directories(${PROJECT_NAME} PRIVATE ${imgui_SOURCE_DIR}/backends)
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC "${imgui_SOURCE_DIR}")


# Link GLFW to your project
target_link_libraries(${PROJECT_NAME} PRIVATE glfw OpenGL::GL)

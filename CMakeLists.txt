cmake_minimum_required(VERSION 3.10)
project(OpenGLExample)

set(CMAKE_CXX_STANDARD 17)

# Find the packages
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(GLEW REQUIRED)

# Add the executable
add_executable(OpenGLExample src/main.cpp)

# Link the libraries
target_link_libraries(OpenGLExample PRIVATE glfw)
target_link_libraries(OpenGLExample PRIVATE imgui::imgui)
target_link_libraries(OpenGLExample PRIVATE GLEW::GLEW)

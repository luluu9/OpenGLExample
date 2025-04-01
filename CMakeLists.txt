cmake_minimum_required(VERSION 3.10)
project(OpenGLExample)

set(CMAKE_CXX_STANDARD 17)

# Find the packages
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(Stb REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add the executable
add_executable(OpenGLExample
    src/main.cpp
    src/Application.cpp
    src/Camera.cpp
    src/GLFWWindow.cpp
    src/InputManager.cpp
    src/Light.cpp
    src/Mesh.cpp
    src/Model.cpp
    src/OpenGLRenderer.cpp
    src/ResourceManager.cpp
    src/Scene.cpp
    src/Texture.cpp
    src/UIManager.cpp
    src/GLShader.cpp
)

add_custom_command(TARGET OpenGLExample POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/res
  $<TARGET_FILE_DIR:OpenGLExample>/res
)

# Add the include directories
target_include_directories(OpenGLExample PRIVATE ${Stb_INCLUDE_DIR})

# Link the libraries
target_link_libraries(OpenGLExample PRIVATE glfw)
target_link_libraries(OpenGLExample PRIVATE imgui::imgui)
target_link_libraries(OpenGLExample PRIVATE GLEW::GLEW)
target_link_libraries(OpenGLExample PRIVATE nlohmann_json::nlohmann_json)

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
    src/core/main.cpp
    src/core/Application.cpp
    src/core/Camera.cpp
    src/rendering/GLFWWindow.cpp
    src/input/InputManager.cpp
    src/core/Light.cpp
    src/core/Mesh.cpp
    src/core/Model.cpp
    src/rendering/OpenGLRenderer.cpp
    src/core/ResourceManager.cpp
    src/scene/Scene.cpp
    src/core/Texture.cpp
    src/ui/UIManager.cpp
    src/rendering/GLShader.cpp
    src/rendering/GLTexture.cpp
    src/rendering/GLModel.cpp
    src/rendering/OpenGLResourceLoader.cpp
    src/rendering/utils/stb_impl.cpp
)

add_custom_command(TARGET OpenGLExample POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/res
  $<TARGET_FILE_DIR:OpenGLExample>/res
)

# Add the include directories
target_include_directories(OpenGLExample PRIVATE
    ${Stb_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# Link the libraries
target_link_libraries(OpenGLExample PRIVATE glfw)
target_link_libraries(OpenGLExample PRIVATE imgui::imgui)
target_link_libraries(OpenGLExample PRIVATE GLEW::GLEW)
target_link_libraries(OpenGLExample PRIVATE nlohmann_json::nlohmann_json)

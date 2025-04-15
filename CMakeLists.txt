############################################
# OpenGLExample Project Configuration
############################################

# Minimum CMake version and project definition
cmake_minimum_required(VERSION 3.10)
project(OpenGLExample VERSION 1.0.0 LANGUAGES CXX)

# Global settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

############################################
# Dependencies
############################################

# Find required packages
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(Stb REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

############################################
# Source files organization
############################################

# Core module files
set(CORE_SOURCES
    src/core/main.cpp
    src/core/Application.cpp
    src/core/Camera.cpp
    src/core/Light.cpp
    src/core/Mesh.cpp
    src/core/Model.cpp
    src/core/ResourceManager.cpp
    src/core/Texture.cpp
)

# Input module files
set(INPUT_SOURCES
    src/input/InputManager.cpp
)

# Rendering module files
set(RENDERING_SOURCES
    src/rendering/opengl/GLFWWindow.cpp
    src/rendering/opengl/GLShader.cpp
    src/rendering/opengl/GLTexture.cpp
    src/rendering/opengl/GLModel.cpp
    src/rendering/opengl/OpenGLResourceLoader.cpp
    src/rendering/opengl/OpenGLRenderer.cpp
    src/rendering/utils/stb_impl.cpp
)

# Scene module files
set(SCENE_SOURCES
    src/scene/Scene.cpp
)

# UI module files
set(UI_SOURCES
    src/ui/UIManager.cpp
)

############################################
# Target configuration
############################################

# Define the executable and its sources
add_executable(${PROJECT_NAME}
    ${CORE_SOURCES}
    ${INPUT_SOURCES}
    ${RENDERING_SOURCES}
    ${SCENE_SOURCES}
    ${UI_SOURCES}
)

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${Stb_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# Link all required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    imgui::imgui
    GLEW::GLEW
    nlohmann_json::nlohmann_json
)

############################################
# Resource handling
############################################

# Copy resources to the build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
    COMMENT "Copying resource files to build directory"
)

############################################
# Build options
############################################

# Enable all warnings with high warning level
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()

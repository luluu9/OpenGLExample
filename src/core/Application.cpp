#include <core/Application.h>
#include <core/ResourceManager.h>
#include <rendering/opengl/GLFWWindow.h>
#include <rendering/opengl/OpenGLRenderer.h>
#include <rendering/opengl/OpenGLResourceLoader.h>
#include <input/InputManager.h>
#include <ui/UIManager.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

void Application::run() {
    window = std::make_unique<GLFWWindow>(1920, 1080, "OpenGL Example");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window->getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    renderer = std::make_unique<OpenGLRenderer>();
    scene = std::make_unique<Scene>();
    inputManager = std::make_unique<InputManager>();
    uiManager = std::make_unique<UIManager>();
    auto resourceLoader = std::make_unique<OpenGLResourceLoader>();
    resourceManager = std::make_unique<ResourceManager>(std::move(resourceLoader));
    resourceManager->loadResources();

    while (!window->shouldClose()) {
        window->clear();
        inputManager->processInput(window->getWindow());
        renderer->render(*scene);
        uiManager->renderUI();
        window->swapBuffers();
        window->pollEvents();
    }
 
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

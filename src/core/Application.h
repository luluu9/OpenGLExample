#pragma once

#include <memory>
#include <rendering/Renderer.h>
#include <scene/Scene.h>
#include <core/Window.h>
#include <input/InputManager.h>
#include <ui/UIManager.h>
#include <core/ResourceManager.h>

class Application {
public:
    void run();

private:
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Scene> scene;
    std::unique_ptr<Window> window;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<UIManager> uiManager;
    std::unique_ptr<ResourceManager> resourceManager;
};

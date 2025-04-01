#pragma once

#include <memory>
#include "Renderer.h"
#include "Scene.h"
#include "Window.h"
#include "InputManager.h"
#include "UIManager.h"
#include "ResourceManager.h"

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

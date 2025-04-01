#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
    virtual ~Window() = default;
    virtual void pollEvents() = 0;
    virtual void swapBuffers() = 0;
    virtual bool shouldClose() const = 0;
    virtual GLFWwindow* getWindow() const = 0;
    virtual void clear() = 0;
};

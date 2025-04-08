#pragma once

#include <core/Window.h>
#include <GLFW/glfw3.h>

class GLFWWindow : public Window {
public:
    GLFWWindow(int width, int height, const char* title);
    ~GLFWWindow();
    void pollEvents() override;
    void swapBuffers() override;
    bool shouldClose() const override;
    GLFWwindow* getWindow() const override;
    void clear() override;
private:
    GLFWwindow* window;
};

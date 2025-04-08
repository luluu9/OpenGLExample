#pragma once

#include <GLFW/glfw3.h>

class InputManager {
public:
    void processInput(GLFWwindow* window);

private:
    GLFWwindow* window;
};

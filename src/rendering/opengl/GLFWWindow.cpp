#include <stdexcept>
#include <GL/glew.h>
#include "GLFWWindow.h"

GLFWWindow::GLFWWindow(int width, int height, const char* title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("Failed to initialize GLEW");
    }
}

GLFWWindow::~GLFWWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GLFWWindow::pollEvents() {
    glfwPollEvents();
}

void GLFWWindow::swapBuffers() {
    glfwSwapBuffers(window);
}

bool GLFWWindow::shouldClose() const {
    return glfwWindowShouldClose(window);
}

GLFWwindow* GLFWWindow::getWindow() const {
    return window;
}

void GLFWWindow::clear() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
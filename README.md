# OpenGLExample

This is a minimal OpenGL project that uses vcpkg for dependency management. All required libraries (GLEW, glfw3, imgui) are automatically handled via the provided configuration files.

## Requirements

- **CMake** 3.10 or newer
- [vcpkg](https://github.com/microsoft/vcpkg)

> **Note:** The configuration is set up by default for Windows, building with Visual Studio 2022.


## Building the Project

1. Clone the repository:
```bash
git clone https://github.com/luluu9/OpenGLExample.git
cd OpenGLExample
```
2. Configure the project using the preset:
```bash
cmake --preset=default ..
```
3. Build the project:
```bash
cmake --build .
```
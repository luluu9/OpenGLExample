# OpenGLExample

This is a minimal OpenGL project that uses vcpkg for dependency management. All required libraries (GLEW, glfw3, imgui) are automatically handled via the provided configuration files.

## Requirements

- [**CMake** 3.10 or newer](https://cmake.org/download/)
- [vcpkg](https://github.com/microsoft/vcpkg)
> **Note:** The configuration is set up by default for Windows, building with Visual Studio 2022. Without VS there may be additional steps required.


## Building the Project

1. Clone the repository:
```bash
git clone https://github.com/luluu9/OpenGLExample.git
cd OpenGLExample
```
2. Set your path to vcpkg in `CMakeUserPresets.json`
```json
"environment": {
    "VCPKG_ROOT": "<your_path_to_vcpkg_root>"
}
```
3. Configure the project using the preset:
```bash
cmake --preset=default build
```
4. Build the project:
```bash
cmake --build build
```

## Running clang-tidy
To use clang-tidy, you have to generate compilation database. At the time of writing it is possible only with Makefile and Ninja generator (CMAKE_EXPORT_COMPILE_COMMANDS=1), so use build-ninja preset:
```bash
cmake --preset=build-ninja
```
Then, run clang-tidy, providing compilation database, e.g:
```bash
clang-tidy -checks="*" -warnings-as-errors=* -p .\build-ninja\ .\src\core\Application.cpp
```
You can also use provided Powershell script to run linter on all project files:
```bash
.\scripts\Run-ClangTidy.ps1
```
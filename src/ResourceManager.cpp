#include "ResourceManager.h"
#include "GLShader.h"
#include "Model.h"
#include "Texture.h"
#include <fstream>

void ResourceManager::loadResources() {
    // Load shaders
    shaders["default"] = std::make_unique<GLShader>();
    shaders["default"]->compile(loadStringFile("res/shaders/default.vert"), loadStringFile("res/shaders/default.frag"));

    // Load models
    MeshData cubeData = {
        { 
            {
                {0.5f, 0.5f, 0.5f}, 
                {0.0f, 0.0f, 1.0f}, 
                {1.0f, 1.0f} 
            },
            {
                {-0.5f, 0.5f, 0.5f},
                {0.0f, 0.0f, 1.0f},
                {0.0f, 1.0f}
            },
            {
                {-0.5f, -0.5f, 0.5f},
                {0.0f, 0.0f, 1.0f},
                {0.0f, 0.0f}
            }
        },
        {
            0, 1, 2,
        }
    };
    models["cube"] = std::make_unique<Model>();
    models["cube"]->loadMesh(cubeData);

    // Load textures
    textures["default"] = std::make_unique<Texture>("res/textures/default.png");
}

Shader* ResourceManager::getShader(const std::string& name) {
    return shaders[name].get();
}

Model* ResourceManager::getModel(const std::string& name) {
    return models[name].get();
}

Texture* ResourceManager::getTexture(const std::string& name) {
    return textures[name].get();
}

std::string ResourceManager::loadStringFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) throw std::runtime_error("Failed to open shader: " + path);
    return std::string(std::istreambuf_iterator<char>(file),
                     std::istreambuf_iterator<char>());
}

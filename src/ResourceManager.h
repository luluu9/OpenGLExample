#pragma once

#include <map>
#include <memory>
#include <string>
#include "Shader.h"
#include "Model.h"
#include "Texture.h"

class ResourceManager {
public:
    void loadResources();
    Shader* getShader(const std::string& name);
    Model* getModel(const std::string& name);
    Texture* getTexture(const std::string& name);
    std::string loadStringFile(const std::string& path);

private:
    std::map<std::string, std::unique_ptr<Shader>> shaders;
    std::map<std::string, std::unique_ptr<Model>> models;
    std::map<std::string, std::unique_ptr<Texture>> textures;
};

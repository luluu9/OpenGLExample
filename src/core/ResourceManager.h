#pragma once

#include <map>
#include <memory>
#include <string>
#include <core/Shader.h>
#include <core/Model.h>
#include <core/Texture.h>

#include <core/ResourceLoader.h>

class ResourceManager {
public:
    ResourceManager(std::unique_ptr<ResourceLoader> loader);
    void loadResources();
    Shader* getShader(const std::string& name);
    Model* getModel(const std::string& name);
    Texture* getTexture(const std::string& name);
    std::string loadStringFile(const std::string& path);

private:
    std::unique_ptr<ResourceLoader> resourceLoader;
    std::map<std::string, std::unique_ptr<Shader>> shaders;
    std::map<std::string, std::unique_ptr<Model>> models;
    std::map<std::string, std::unique_ptr<Texture>> textures;
};

#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Model.h"
#include "Light.h"
#include "Camera.h"
#include "Shader.h"

class Scene {
public:
    Scene();
    void addModel(const std::string& name, std::unique_ptr<Model> model);
    void addLight(std::unique_ptr<Light> light);
    void removeLight(int index);
    void saveToFile(const std::string& path);
    static Scene* loadFromFile(const std::string& path);

    const std::vector<std::unique_ptr<Model>>& getObjects() const;
    Shader* getShader() const;

private:
    std::vector<std::unique_ptr<Model>> objects;
    std::vector<std::unique_ptr<Light>> lights;
    Camera camera;
    Shader* shader;
};

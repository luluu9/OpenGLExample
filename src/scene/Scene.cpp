#include <scene/Scene.h>
#include <fstream>
#include <nlohmann/json.hpp>

Scene::Scene() : shader(nullptr) {}

void Scene::addModel(const std::string& name, std::unique_ptr<Model> model) {
    objects.push_back(std::move(model));
}

void Scene::addLight(std::unique_ptr<Light> light) {
    lights.push_back(std::move(light));
}

void Scene::removeLight(int index) {
    if (index >= 0 && index < lights.size()) {
        lights.erase(lights.begin() + index);
    }
}

void Scene::saveToFile(const std::string& path) {
    nlohmann::json j;
    j["objects"] = nlohmann::json::array();
    for (const auto& model : objects) {
        nlohmann::json obj;
        obj["model"] = model->getName();
        obj["position"] = { model->getPosition().x, model->getPosition().y, model->getPosition().z };
        obj["shader"] = model->getShaderName();
        j["objects"].push_back(obj);
    }

    j["lights"] = nlohmann::json::array();
    for (const auto& light : lights) {
        nlohmann::json l;
        l["position"] = { light->getPosition().x, light->getPosition().y, light->getPosition().z };
        l["color"] = { light->getColor().x, light->getColor().y, light->getColor().z };
        l["intensity"] = light->getIntensity();
        j["lights"].push_back(l);
    }

    j["camera"]["position"] = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
    j["camera"]["rotation"] = { camera.getRotation().x, camera.getRotation().y, camera.getRotation().z };

    std::ofstream file(path);
    file << j.dump(4);
}

Scene* Scene::loadFromFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return nullptr;
    }

    nlohmann::json j;
    file >> j;

    auto scene = new Scene();

    for (const auto& obj : j["objects"]) {
        auto model = std::make_unique<Model>();
        model->setName(obj["model"]);
        model->setPosition({ obj["position"][0], obj["position"][1], obj["position"][2] });
        model->setShaderName(obj["shader"]);
        scene->addModel(obj["model"], std::move(model));
    }

    for (const auto& l : j["lights"]) {
        auto light = std::make_unique<Light>(
            glm::vec3(l["position"][0], l["position"][1], l["position"][2]),
            glm::vec3(l["color"][0], l["color"][1], l["color"][2]),
            l["intensity"]
        );
        scene->addLight(std::move(light));
    }

    scene->camera.setPosition({ j["camera"]["position"][0], j["camera"]["position"][1], j["camera"]["position"][2] });
    scene->camera.setRotation({ j["camera"]["rotation"][0], j["camera"]["rotation"][1], j["camera"]["rotation"][2] });

    return scene;
}

const std::vector<std::unique_ptr<Model>>& Scene::getObjects() const {
    return objects;
}

Shader* Scene::getShader() const {
    return shader;
}

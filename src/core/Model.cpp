#include <core/Model.h>
#include <core/Shader.h>

void Model::draw(Shader& shader) {
    for (auto& mesh : meshes) {
        mesh.draw();
    }
}

void Model::loadMesh(const MeshData& data) {
    meshes.emplace_back(data.vertices, data.indices);
}

std::string Model::getName() const {
    return name;
}

glm::vec3 Model::getPosition() const {
    return glm::vec3(transform[3]);
}

std::string Model::getShaderName() const {
    return shaderName;
}

void Model::setName(const std::string& name) {
    this->name = name;
}

void Model::setPosition(const glm::vec3& position) {
    transform[3] = glm::vec4(position, 1.0f);
}

void Model::setShaderName(const std::string& shaderName) {
    this->shaderName = shaderName;
}

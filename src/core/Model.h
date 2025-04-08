#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <core/Mesh.h>
#include <core/Texture.h>

struct MeshData {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

class Model {
public:
    void draw(class Shader& shader);
    void loadMesh(const MeshData& data);

    std::string getName() const;
    glm::vec3 getPosition() const;
    std::string getShaderName() const;

    void setName(const std::string& name);
    void setPosition(const glm::vec3& position);
    void setShaderName(const std::string& shaderName);

private:
    std::vector<Mesh> meshes;
    std::vector<Texture> textures;
    glm::mat4 transform;
    std::string name;
    std::string shaderName;
};

#pragma once

#include <glm/glm.hpp>

class Camera {
public:
    Camera();
    Camera(const glm::vec3& position, const glm::vec3& rotation);

    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;

    void setPosition(const glm::vec3& position);
    void setRotation(const glm::vec3& rotation);

private:
    glm::vec3 position;
    glm::vec3 rotation;
};

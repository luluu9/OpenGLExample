#include "Camera.h"

Camera::Camera() : position(glm::vec3(0.0f)), rotation(glm::vec3(0.0f)) {}

Camera::Camera(const glm::vec3& position, const glm::vec3& rotation)
    : position(position), rotation(rotation) {}

glm::vec3 Camera::getPosition() const {
    return position;
}

glm::vec3 Camera::getRotation() const {
    return rotation;
}

void Camera::setPosition(const glm::vec3& position) {
    this->position = position;
}

void Camera::setRotation(const glm::vec3& rotation) {
    this->rotation = rotation;
}

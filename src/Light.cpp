#include "Light.h"

Light::Light(const glm::vec3& position, const glm::vec3& color, float intensity)
    : position(position), color(color), intensity(intensity) {}

glm::vec3 Light::getPosition() const {
    return position;
}

glm::vec3 Light::getColor() const {
    return color;
}

float Light::getIntensity() const {
    return intensity;
}

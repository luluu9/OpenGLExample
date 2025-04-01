#pragma once

#include <glm/glm.hpp>

class Light {
public:
    Light(const glm::vec3& position, const glm::vec3& color, float intensity);

    glm::vec3 getPosition() const;
    glm::vec3 getColor() const;
    float getIntensity() const;

private:
    glm::vec3 position;
    glm::vec3 color;
    float intensity;
};

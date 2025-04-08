#pragma once

#include <scene/Scene.h>

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void render(const Scene& scene) = 0;
};

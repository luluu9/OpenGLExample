#pragma once

#include <core/Shader.h>
#include <core/Texture.h>
#include <core/Model.h>
#include <memory>

class ResourceLoader {
public:
    virtual ~ResourceLoader() = default;
    virtual std::unique_ptr<Shader> createShader() = 0;
    virtual std::unique_ptr<Texture> createTexture() = 0;
    virtual std::unique_ptr<Model> createModel() = 0;
};
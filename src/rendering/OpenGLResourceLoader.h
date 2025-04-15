#pragma once

#include <core/ResourceLoader.h>

class OpenGLResourceLoader : public ResourceLoader {
public:
    std::unique_ptr<Shader> createShader() override;
    std::unique_ptr<Texture> createTexture() override;
    std::unique_ptr<Model> createModel() override;
};
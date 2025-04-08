#pragma once

#include <rendering/Renderer.h>

class OpenGLRenderer : public Renderer {
public:
    void render(const Scene& scene) override;
    std::unique_ptr<Shader> createShader(const std::string& vertexSource, const std::string& fragmentSource);
    std::unique_ptr<Model> createModel(const MeshData& data);
};

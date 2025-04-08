#include <rendering/OpenGLRenderer.h>
#include <rendering/GLShader.h>
#include <core/Model.h>

void OpenGLRenderer::render(const Scene& scene) {
    for (const auto& model : scene.getObjects()) {
        model->draw(*scene.getShader());
    }
}

std::unique_ptr<Shader> OpenGLRenderer::createShader(const std::string& vertexSource, const std::string& fragmentSource) {
    auto shader = std::make_unique<GLShader>();
    shader->compile(vertexSource, fragmentSource);
    return shader;
}

std::unique_ptr<Model> OpenGLRenderer::createModel(const MeshData& data) {
    auto model = std::make_unique<Model>();
    model->loadMesh(data);
    return model;
}

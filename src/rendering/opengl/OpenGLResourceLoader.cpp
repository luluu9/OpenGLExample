#include "OpenGLResourceLoader.h"
#include "GLShader.h"
#include "GLTexture.h"
#include "GLModel.h"

std::unique_ptr<Shader> OpenGLResourceLoader::createShader() {
    return std::make_unique<GLShader>();
}

std::unique_ptr<Texture> OpenGLResourceLoader::createTexture() {
    return std::make_unique<GLTexture>();
}

std::unique_ptr<Model> OpenGLResourceLoader::createModel() {
    return std::make_unique<GLModel>();
}
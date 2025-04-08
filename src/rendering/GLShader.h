#pragma once

#include <core/Shader.h>
#include <GL/glew.h>
#include <unordered_map>
#include <string>

class GLShader : public Shader {
public:
    GLShader();
    ~GLShader() override;

    // Interface implementation
    void compile(const std::string& vertexSrc, 
                const std::string& fragmentSrc) override;
    void compile(const std::string& vertexSrc,
                const std::string& fragmentSrc,
                const std::string& geometrySrc) override;
    void use() override;
    void setUniform(const std::string& name, 
                   const void* value) override;

    // Additional functionality
    GLuint getId() const { return programID; }
    void destroy();

    // Type-safe uniform setters
    template<typename T>
    void setUniformSafe(const std::string& name, const T& value);

private:
    GLuint programID = 0;
    std::unordered_map<std::string, GLint> uniformCache;
    
    GLint getUniformLocation(const std::string& name);
    void checkCompileErrors(GLuint shader, const std::string& type);
    void checkLinkErrors();
};

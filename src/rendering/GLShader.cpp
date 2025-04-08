#include <rendering/GLShader.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

GLShader::GLShader() {
    programID = glCreateProgram();
}

GLShader::~GLShader() {
    destroy();
}

void GLShader::compile(const std::string& vertexSrc, 
                      const std::string& fragmentSrc) {
    compile(vertexSrc, fragmentSrc, "");
}

void GLShader::compile(const std::string& vertexSrc,
                     const std::string& fragmentSrc,
                     const std::string& geometrySrc) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vCode = vertexSrc.c_str();
    glShaderSource(vertexShader, 1, &vCode, nullptr);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fCode = fragmentSrc.c_str();
    glShaderSource(fragmentShader, 1, &fCode, nullptr);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    GLuint geometryShader = 0;
    if(!geometrySrc.empty()) {
        geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
        const char* gCode = geometrySrc.c_str();
        glShaderSource(geometryShader, 1, &gCode, nullptr);
        glCompileShader(geometryShader);
        checkCompileErrors(geometryShader, "GEOMETRY");
    }

    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    if(geometryShader) glAttachShader(programID, geometryShader);
    
    glLinkProgram(programID);
    checkLinkErrors();

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if(geometryShader) glDeleteShader(geometryShader);
}

void GLShader::use() {
    glUseProgram(programID);
}

GLint GLShader::getUniformLocation(const std::string& name) {
    auto it = uniformCache.find(name);
    if(it != uniformCache.end()) return it->second;
    
    GLint location = glGetUniformLocation(programID, name.c_str());
    if(location == -1) {
        std::cerr << "Warning: Uniform '" << name << "' not found" << std::endl;
    }
    uniformCache[name] = location;
    return location;
}

void GLShader::setUniform(const std::string& name, const void* value) {
    GLint loc = getUniformLocation(name);
    if(loc != -1) {
        glUniformMatrix4fv(loc, 1, GL_FALSE, static_cast<const float*>(value));
    }
}

template<typename T>
void GLShader::setUniformSafe(const std::string& name, const T& value) {
    use();
    GLint loc = getUniformLocation(name);
    if(loc == -1) return;
    
    if constexpr(std::is_same_v<T, float>) {
        glUniform1f(loc, value);
    } else if constexpr(std::is_same_v<T, int>) {
        glUniform1i(loc, value);
    } else if constexpr(std::is_same_v<T, glm::mat4>) {
        glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
    }
}

void GLShader::checkCompileErrors(GLuint shader, const std::string& type) {
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        GLchar infoLog[1024];
        glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
        std::cerr << "SHADER_COMPILATION_ERROR (" << type << "):\n" 
                 << infoLog << std::endl;
        throw std::runtime_error("Shader compilation failed");
    }
}

void GLShader::checkLinkErrors() {
    GLint success;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if(!success) {
        GLchar infoLog[1024];
        glGetProgramInfoLog(programID, 1024, nullptr, infoLog);
        std::cerr << "SHADER_LINK_ERROR:\n" << infoLog << std::endl;
        throw std::runtime_error("Shader linking failed");
    }
}

void GLShader::destroy() {
    if(programID) {
        glDeleteProgram(programID);
        programID = 0;
    }
    uniformCache.clear();
}

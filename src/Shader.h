#pragma once

#include <string>

class Shader {
public:
    virtual ~Shader() = default;
    
    virtual void compile(const std::string& vertexSrc, 
                        const std::string& fragmentSrc) = 0;
    virtual void use() = 0;
    virtual void setUniform(const std::string& name, 
                          const void* value) = 0;

    virtual void compile(const std::string& vertexSrc,
                       const std::string& fragmentSrc,
                       const std::string& geometrySrc) = 0;
};
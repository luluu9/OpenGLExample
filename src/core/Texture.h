#pragma once

#include <string>

class Texture {
public:
    virtual ~Texture() = default;
    virtual void load(const std::string& path) = 0;
    virtual void bind() const;

protected:
    unsigned int textureID = 0;
};

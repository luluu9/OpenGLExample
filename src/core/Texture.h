#pragma once

#include <string>

class Texture {
public:
    Texture(const std::string& path);
    void bind() const;

private:
    unsigned int textureID;
};

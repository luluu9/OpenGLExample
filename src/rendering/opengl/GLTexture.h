#pragma once

#include <core/Texture.h>

class GLTexture : public Texture {
public:
    GLTexture() = default;
    
    void load(const std::string& path) override;
    void bind() const override;
};
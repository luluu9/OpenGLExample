#include "GLTexture.h"
#include <GL/glew.h>
#include <stb_image.h>
#include <iostream>

void GLTexture::load(const std::string& path) {
    // Generate texture ID if not already created
    if (textureID == 0) {
        glGenTextures(1, &textureID);
    }

    // Load image
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // flip images vertically
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    
    if (data) {
        // Determine format based on number of channels
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;
        
        // Bind the texture
        bind();
        
        // Set texture parameters for OpenGL rendering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        // Upload texture data to GPU
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cerr << "Failed to load texture: " << path << std::endl;
    }
    
    // Free image data
    stbi_image_free(data);
}

void GLTexture::bind() const {
    // Call base class bind implementation
    Texture::bind();
}
//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <Rendering/Essentials/Texture.h>
#include <glad/glad.h>
#include <logger/Logger.h>

namespace otterus_rendering
{
    Texture::Texture(const TextureData& data) {
        glGenTextures(1, &m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);

        // Set wrapping and filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        GLenum format = data.channels == 4 ? GL_RGBA : GL_RGB;

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            format,
            data.width,
            data.height,
            0,
            format,
            GL_UNSIGNED_BYTE,
            data.pixels
        );

        glGenerateMipmap(GL_TEXTURE_2D);
    }

    Texture::Texture(unsigned int width, unsigned int height) {
        // Generate and bind the texture
        glGenTextures(1, &m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);

        // Set wrapping and filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Allocate memory on the GPU.
        // Passing nullptr creates a blank/empty texture of the specified dimensions.
        // Note: GL_RGBA is used here as a safe default; adjust format if you only want RGB.
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

        // Optional: Unbind texture to prevent accidental modifications elsewhere
        glBindTexture(GL_TEXTURE_2D, 0);
    }


    void Texture::Bind() const {
        glBindTexture(GL_TEXTURE_2D, m_textureID);
    }
}
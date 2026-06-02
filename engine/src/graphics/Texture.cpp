//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//
#define STB_IMAGE_IMPLEMENTATION
#include <entrypoint/Application.h>
#include <graphics/Texture.h>
#include <stb/stb_image.h>
#include <glad/glad.h>

#include "core/Logger.h"

engine::Texture::Texture(const std::string &path) {
    load(path);
}

engine::Texture::Texture(ui32 width, ui32 height) {
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

void engine::Texture::load(const std::string &path) {
    // Generate and bind
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    // Set wrapping and filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load image data
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    } else {
        CORE_ERROR("Failed to load texture.");
    }
}

void engine::Texture::Bind() const {
    glBindTexture(GL_TEXTURE_2D, m_textureID);
}

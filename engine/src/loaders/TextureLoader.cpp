//
// Created by umair on 6/9/2026.
//

#include <loaders/TextureLoader.h>

#include <stb_image.h>

#include "core/Logger.h"

engine::TextureData engine::TextureLoader::Load(const std::string &path) {
    TextureData data;
    // Load image data
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    data.pixels = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data.pixels) {
        stbi_image_free(data.pixels);
    } else {
        CORE_ERROR("Failed to load texture.");
    }
    return data;
}

void engine::TextureLoader::Free(TextureData &data) {
        stbi_image_free(data.pixels);
        data.pixels = nullptr;
}

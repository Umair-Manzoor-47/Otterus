//
// Created by umair on 6/9/2026.
//

#include <loaders/TextureLoader.h>

#include <stb_image.h>

#include "../../../OTTERUS_LOGGER/logger/Logger.h"

engine::TextureData engine::TextureLoader::Load(const std::string &path) {
    TextureData data;
    stbi_set_flip_vertically_on_load(true);
    data.pixels = stbi_load(path.c_str(), &data.width, &data.height, &data.channels, 0);
    if (!data.pixels) {
        CORE_ERROR("Failed to load texture.");
    }
    return data;
}

void engine::TextureLoader::Free(TextureData &data) {
        stbi_image_free(data.pixels);
        data.pixels = nullptr;
}

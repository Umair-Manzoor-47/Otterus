#include <Rendering/Essentials/TextureLoader.h>
#include <stb_image.h>
#include <logger/Logger.h>

namespace otterus_rendering
{
    std::shared_ptr<Texture> TextureLoader::Load(const std::string &path) {
        TextureData data;
        stbi_set_flip_vertically_on_load(true);
        data.pixels = stbi_load(path.c_str(), &data.width, &data.height, &data.channels, 0);
        if (!data.pixels) {
            CORE_ERROR("Failed to load texture.");
        }
        auto texture = std::make_shared<Texture>(data);
        Free(data);
        return texture;
    }

    void TextureLoader::Free(TextureData &data) {
        stbi_image_free(data.pixels);
        data.pixels = nullptr;
    }
}
#pragma once
#include <Rendering/Essentials/Texture.h>
#include <string>
#include <memory>

namespace otterus_rendering {
    class TextureLoader {
    public:
        static std::shared_ptr<Texture> Load(const std::string& path);
        static void Free(TextureData& data);
    };
} // engine

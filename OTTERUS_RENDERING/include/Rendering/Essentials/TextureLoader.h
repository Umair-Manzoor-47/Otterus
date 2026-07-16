#pragma once
#include <Rendering/Essentials/Texture.h>
#include <string>


namespace otterus_rendering {
    class TextureLoader {
    public:
        static TextureData Load(const std::string& path);
        static void Free(TextureData& data);
    };
} // engine

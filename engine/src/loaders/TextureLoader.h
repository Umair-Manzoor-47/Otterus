#pragma once
#include <core/Common.h>


namespace engine {
    class TextureLoader {
    public:
        static TextureData Load(const std::string& path);
        static void Free(TextureData& data);
    };
} // engine

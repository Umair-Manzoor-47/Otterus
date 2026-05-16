//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <core/Core.h>
#include <string>

namespace engine {
    class Texture {
    public:
        Texture(const std::string& path);
        void Bind();

    private:
        ui32 m_textureID;

        void load(const std::string& path);
    };
} // engine

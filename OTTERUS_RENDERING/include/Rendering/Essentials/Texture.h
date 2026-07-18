//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//
#pragma once

namespace otterus_rendering {
    struct TextureData {
        unsigned char* pixels = nullptr;
        int width, height, channels;
    };
    class Texture {
    public:
        Texture();
        Texture(unsigned int width, unsigned int height);
        Texture(const TextureData& data);
        void Bind() const;
        
        const unsigned int GetID() const { return m_textureID; }

    private:
        unsigned int m_textureID;
    };
} // engine

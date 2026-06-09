//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//
#pragma once
#include <core/Core.h>
#include <core/Common.h>

namespace engine {
    class Texture {
    public:
        Texture(ui32 width, ui32 height);
        Texture(const TextureData& data);
        void Bind() const;
        
        const ui32 GetID() const { return m_textureID; }

    private:
        ui32 m_textureID;
    };
} // engine

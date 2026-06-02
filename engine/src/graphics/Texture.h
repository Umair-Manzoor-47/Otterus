//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//
#pragma once
#include <core/Core.h>
#include <string>

namespace engine {
    class Texture {
    public:
        Texture(ui32 width, ui32 height);
        Texture(const std::string& path);
        void Bind() const;
        
        const ui32 GetID() const { return m_textureID; }

    private:
        ui32 m_textureID;

        void load(const std::string& path);
    };
} // engine

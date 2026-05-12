//
// Created by umair on 5/3/2026.
//

#pragma once
#include <string>
#include <core/Core.h>

namespace engine {
    struct BaseDesc
    {
    };
    struct ShaderDesc
    {
        std::string vertexPath;
        std::string fragmentPath;
    };
    struct MeshDesc
    {
        f32*   vertices;
        size_t size;        // byte size of vertices array
        ui32*  indices;
        size_t index_size;  // byte size of indices array
    };

}


#pragma once
#include <core/Common.h>

namespace engine{
class MeshLoader {
public:
    static MeshData Load(const std::string& path);
};

}


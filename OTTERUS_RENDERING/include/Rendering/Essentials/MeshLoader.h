#pragma once
#include <Rendering/Essentials/Mesh.h>
#include <string>

namespace otterus_rendering{
class MeshLoader {
public:
    static MeshData Load(const std::string& path);
};

}


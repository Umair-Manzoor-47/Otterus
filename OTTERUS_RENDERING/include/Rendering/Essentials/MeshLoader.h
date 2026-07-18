#pragma once
#include <Rendering/Essentials/Mesh.h>
#include <string>
#include <memory>
namespace otterus_rendering{
class MeshLoader {
public:
    static std::shared_ptr<Mesh> Load(const std::string& path);
};

}


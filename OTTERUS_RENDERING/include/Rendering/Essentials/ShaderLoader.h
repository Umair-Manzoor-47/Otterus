#pragma once
#include <string>
#include <Rendering/Essentials/Shader.h>
namespace otterus_rendering {
    class ShaderLoader {
    public:
        static ShaderSource Load(const ShaderDesc& desc);
    private:
        static std::string readFile(const std::string& path);
    };
} // engine



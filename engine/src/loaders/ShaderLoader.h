#pragma once
#include <string>
#include <core/Common.h>
namespace engine {
    class ShaderLoader {
    public:
        static ShaderSource Load(const ShaderDesc& desc);
    private:
        static std::string readFile(const std::string& path);
    };
} // engine



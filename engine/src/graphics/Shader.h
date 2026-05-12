#pragma once
#include <core/Core.h>
#include <string>
#include <core/Common.h>
#include "glad/glad.h"

namespace engine {
    class Shader {
    public:
        Shader() = default;
        void Load(const ShaderDesc &desc);
        void Bind();
        ui32 GetProgram() const;

    private:
        ui32 m_ShaderProgram;
        i32 m_Success;
        ui32 m_vertexShader;
        ui32 m_fragmentShader;

        std::string readFile(const std::string& path);
        void compile(const std::string& vertexCode, const std::string& fragmentCode);
        ui32 createShader(const std::string &code, GLenum type);
        void deleteShaders();
    };
}

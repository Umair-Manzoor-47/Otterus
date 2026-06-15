#pragma once
#include <core/Core.h>
#include <string>
#include <core/Common.h>
#include <glad/glad.h>

namespace engine {
    class Shader {
    public:
        Shader() = default;
        void Load(const ShaderSource &source);
        void Bind() const;
        ui32 GetProgram() const;
        void SetUniform(const std::string& name, const glm::mat4& matrix) const;
        void SetUniform(const std::string& name, const glm::vec3& value) const;
        void SetUniform(const std::string& name, float value) const;

    private:
        ui32 m_ShaderProgram;
        i32 m_Success;
        ui32 m_vertexShader;
        ui32 m_fragmentShader;

        void compile(const std::string& vertexCode, const std::string& fragmentCode);
        ui32 createShader(const std::string &code, GLenum type);
        void deleteShaders();
    };
}

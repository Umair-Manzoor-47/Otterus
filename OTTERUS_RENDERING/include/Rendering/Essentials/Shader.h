#pragma once
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace otterus_rendering {
    struct ShaderDesc
    {
        std::string vertexPath;
        std::string fragmentPath;
    };
    struct ShaderSource {
        std::string vertexCode;
        std::string fragmentCode;
    };
    class Shader {
    public:
        Shader() = default;
        void Load(const ShaderSource &source);
        void Bind() const;
        unsigned int GetProgram() const;
        void SetUniform(const std::string& name, const glm::mat4& matrix) const;
        void SetUniform(const std::string& name, const glm::vec3& value) const;
        void SetUniform(const std::string& name, float value) const;

    private:
        unsigned int m_ShaderProgram;
        signed int m_Success;
        unsigned int m_vertexShader;
        unsigned int m_fragmentShader;

        void compile(const std::string& vertexCode, const std::string& fragmentCode);
        unsigned int createShader(const std::string &code, GLenum type);
        void deleteShaders();
    };
}

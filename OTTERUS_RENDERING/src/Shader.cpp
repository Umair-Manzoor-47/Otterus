#include <logger/Logger.h>
#include <Rendering/Essentials/Shader.h>
#include <glm/gtc/type_ptr.hpp>

namespace otterus_rendering
{
    void Shader::Load(const ShaderSource &source) {

        compile(source.vertexCode, source.fragmentCode);
        deleteShaders();
    }

    void Shader::Bind() const {
        glUseProgram(m_ShaderProgram);
        glUniform1i(glGetUniformLocation(m_ShaderProgram, "Texture"), 0);
    }

    unsigned int Shader::GetProgram() const {
        return m_ShaderProgram;
    }


    void Shader::compile(const std::string &vertexCode, const std::string &fragmentCode) {
        m_ShaderProgram = glCreateProgram();
        m_vertexShader = createShader(vertexCode, GL_VERTEX_SHADER);
        m_fragmentShader = createShader(fragmentCode, GL_FRAGMENT_SHADER);

        glAttachShader(m_ShaderProgram, m_vertexShader);
        glAttachShader(m_ShaderProgram, m_fragmentShader);
        glLinkProgram(m_ShaderProgram);

        glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &m_Success);
        if (!m_Success) {
            char infoLog[512];
            glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
            CORE_ERROR(infoLog);
        }
    }

    unsigned int Shader::createShader(const std::string &code, GLenum type) {
        const char* src = code.c_str();
        const unsigned int shader = glCreateShader(type);
        // compile shader
        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);
        // failure checking
        glGetShaderiv(shader, GL_COMPILE_STATUS, &m_Success);
        if (!m_Success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            CORE_ERROR(infoLog);
        }
        return shader;
    }

    void Shader::deleteShaders() {
        glDeleteShader(m_vertexShader);
        glDeleteShader(m_fragmentShader);
    }

    void Shader::SetUniform(const std::string &name, const glm::mat4 &matrix) const
    {
        GLint location = glGetUniformLocation(
           m_ShaderProgram,
           name.c_str()
       );

        if (location == -1)
        {
            CORE_WARN("Uniform not found");
            return;
        }

        glUniformMatrix4fv(
            location,
            1,
            GL_FALSE,
            glm::value_ptr(matrix)
        );
    }

    void Shader::SetUniform(const std::string& name, const glm::vec3& value) const {
        GLint location = glGetUniformLocation(m_ShaderProgram, name.c_str());
        if (location == -1) {
            CORE_WARN("Uniform not found: {}");
            return;
        }
        glUniform3fv(location, 1, glm::value_ptr(value));
    }

    void Shader::SetUniform(const std::string& name, float value) const {
        GLint location = glGetUniformLocation(m_ShaderProgram, name.c_str());
        if (location == -1) return;
        glUniform1f(location, value);
    }
}
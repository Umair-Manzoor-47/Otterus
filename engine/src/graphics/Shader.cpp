#include <core/Logger.h>
#include <graphics/Shader.h>
#include <glm/gtc/type_ptr.hpp>

void engine::Shader::Load(const ShaderSource &source) {

    compile(source.vertexCode, source.fragmentCode);
    deleteShaders();
}

void engine::Shader::Bind() const {
    glUseProgram(m_ShaderProgram);
    glUniform1i(glGetUniformLocation(m_ShaderProgram, "Texture"), 0);
}

engine::ui32 engine::Shader::GetProgram() const {
    return m_ShaderProgram;
}


void engine::Shader::compile(const std::string &vertexCode, const std::string &fragmentCode) {
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

engine::ui32 engine::Shader::createShader(const std::string &code, GLenum type) {
    const char* src = code.c_str();
    const ui32 shader = glCreateShader(type);
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

void engine::Shader::deleteShaders() {
        glDeleteShader(m_vertexShader);
        glDeleteShader(m_fragmentShader);
}

void engine::Shader::SetUniform(const std::string &name, const glm::mat4 &matrix) const
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

void engine::Shader::SetUniform(const std::string& name, const glm::vec3& value) const {
    GLint location = glGetUniformLocation(m_ShaderProgram, name.c_str());
    if (location == -1) {
        CORE_WARN("Uniform not found: {}");
        return;
    }
    glUniform3fv(location, 1, glm::value_ptr(value));
}

void engine::Shader::SetUniform(const std::string& name, float value) const {
    GLint location = glGetUniformLocation(m_ShaderProgram, name.c_str());
    if (location == -1) return;
    glUniform1f(location, value);
}
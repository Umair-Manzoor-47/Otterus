//
// Created by umair on 5/9/2026.
//
#include <graphics/GraphicsEngine.h>

void engine::GraphicsEngine::SetShader(const ShaderDesc &desc) {
    m_shader.Load(desc);
}

void engine::GraphicsEngine::SetMesh(const MeshDesc& desc) {
    m_mesh = std::make_unique<Mesh>(desc);
}

void engine::GraphicsEngine::SetTexture(const std::string &path) {
    m_texture = std::make_unique<Texture>(path);
}

void engine::GraphicsEngine::Draw(const glm::mat4& projection, const glm::mat4& view){
    m_shader.Bind();
    m_texture->Bind();
    m_shader.SetUniform("projection", projection);
    m_shader.SetUniform("view", view);
    m_mesh->Draw();
}

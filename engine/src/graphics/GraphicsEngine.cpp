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

void engine::GraphicsEngine::Draw() {
    m_shader.Bind();
    m_mesh->Draw();
}

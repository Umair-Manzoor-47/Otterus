//
// Created by umair on 5/9/2026.
//
#pragma once
#include <core/Core.h>
#include <fstream>
#include <sstream>

#include <graphics/Mesh.h>
#include <graphics/Shader.h>

#include <graphics/Texture.h>

namespace engine {
    class GraphicsEngine {

    public:
        GraphicsEngine() = default;
        void SetShader(const ShaderDesc &desc);
        void SetMesh(const MeshDesc &desc);
        void SetTexture(const std::string& path);
        void Draw(const glm::mat4& projection, const glm::mat4& view,
            const glm::mat4& model);
    private:
        Shader m_shader;
        std::unique_ptr<Mesh> m_mesh;
        std::unique_ptr<Texture> m_texture;
        
        
    };


}


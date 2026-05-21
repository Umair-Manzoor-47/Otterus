//
// Created by umair on 5/9/2026.
//
#pragma once
#include <core/Core.h>
#include <core/Common.h>
#include <fstream>
#include <sstream>

#include <graphics/Mesh.h>
#include <graphics/Shader.h>

#include <graphics/Texture.h>

namespace engine {
    class GraphicsEngine {

    public:
        GraphicsEngine() = default;


        void Draw(
            const Mesh& mesh,
            const Shader& shader,
            const Texture* texture,
            const RenderCamera& camera,
            const RenderLight& light,
            const glm::mat4& model
        );
    private:
        Shader m_shader;
        std::unique_ptr<Mesh> m_mesh;
        std::unique_ptr<Texture> m_texture;
        
        
    };


}


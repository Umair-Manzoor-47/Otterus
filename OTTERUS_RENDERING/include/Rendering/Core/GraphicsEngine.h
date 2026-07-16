//
// Created by umair on 5/9/2026.
//
#pragma once
#include <fstream>
#include <sstream>
#include <memory>

#include <Rendering/Essentials/Mesh.h>
#include <Rendering/Essentials/Shader.h>
#include <Rendering/Essentials/Texture.h>
#include <Rendering/Core/Camera.h>
#include <Rendering/Essentials/Material.h>

namespace otterus_rendering {
    struct RenderLight {
        glm::vec3 position;
        glm::vec3 color;
    };
    class GraphicsEngine {

    public:
        GraphicsEngine() = default;


        void Draw(
            const Mesh& mesh,
            const Shader& shader,
            const Material* material,
            const otterus_rendering::RenderCamera& camera,
            const RenderLight& light,
            const glm::mat4& model
        );
    private:
        Shader m_shader;
        std::unique_ptr<Mesh> m_mesh;
        std::unique_ptr<Texture> m_texture;
    };


}


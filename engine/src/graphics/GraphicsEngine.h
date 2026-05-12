//
// Created by umair on 5/9/2026.
//
#pragma once
#include <core/Core.h>
#include <fstream>
#include <sstream>

#include <graphics/Mesh.h>
#include <graphics/Shader.h>

namespace engine {
    class GraphicsEngine {

    public:
        GraphicsEngine() = default;
        void SetShader(const ShaderDesc &desc);
        void SetMesh(const MeshDesc &desc);

        void Draw();
    private:
        Shader m_shader;
        std::unique_ptr<Mesh> m_mesh;
        
        
    };


}


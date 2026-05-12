//
// Created by umair on 5/9/2026.
//
#pragma once
#include <core/Core.h>
#include <fstream>
#include <sstream>

#include "Shader.h"

namespace engine {
    class GraphicsEngine {

    public:
        GraphicsEngine() = default;
        void SetShader(const ShaderDesc &desc);
        void RunGraphicsProgram(float vertices[], size_t size, ui32 indices[], size_t index_size);
        void Draw();
    private:
        ui32 VBO;
        i32 success;
        ui32 VAO;
        ui32 EBO;
        Shader m_shader;

        void initVertexBuffer(float vertices[], size_t size);
        void initElementBuffer(ui32 indices[], size_t index_size);
        void linkVertexAttributes();
        

        void createVAO();
        
    };


}


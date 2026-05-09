//
// Created by umair on 5/9/2026.
//
#pragma once
#include "core/Core.h"

namespace engine {
    class graphics {
    private:
        ui32 VBO;
        ui32 vertexShader;
        ui32 fragmentShader;
        i32 success;
        ui32 shaderProgram;

        void initVertexBuffer(float vertices[]);
        void createVertexShader();
        void createFragmentShader();

        void createShaderProgram();
        void destroyVertexBuffer();

        void linkVertexAttributes();
    };


}


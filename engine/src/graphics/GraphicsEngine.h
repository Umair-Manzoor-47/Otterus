//
// Created by umair on 5/9/2026.
//
#pragma once
#include <core/Core.h>
#include <fstream>
#include <sstream>
namespace engine {
    class GraphicsEngine {

    public:
        void RunGraphicsProgram(float vertices[], size_t size, ui32 indices[], size_t index_size);
        void Draw();
    private:
        ui32 VBO;
        ui32 vertexShader;
        ui32 fragmentShader;
        i32 success;
        ui32 shaderProgram;
        ui32 VAO;

        ui32 EBO;
        std::string vertexShaderCode;
        std::string fragmentShaderCode;

        void readShadersSources(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        void initVertexBuffer(float vertices[], size_t size);
        void initElementBuffer(ui32 indices[], size_t index_size);
        void createVertexShader();
        void createFragmentShader();

        void createShaderProgram();
        void deletShaders();

        void linkVertexAttributes();

        void createVAO();

        std::string readFile(const std::string& path);
    };


}


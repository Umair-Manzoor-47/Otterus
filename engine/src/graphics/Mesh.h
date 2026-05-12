#pragma once
#include <core/Common.h>
#include <glad/glad.h>
#include <core/Core.h>
namespace engine
{
    class Mesh
    {
    public:
        Mesh(const MeshDesc& desc);
        void Draw();
    private:
        ui32 m_VAO = 0;
        ui32 m_VBO = 0;
        ui32 m_EBO = 0;
        i32 m_count = 0;

        void initVertexArray();
        void initVertexBuffer(float vertices[], size_t size);
        void initElementBuffer(ui32 indices[], size_t index_size);
        void linkVertexAttributes();
    };
    
}

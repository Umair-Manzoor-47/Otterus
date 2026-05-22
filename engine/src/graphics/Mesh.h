#pragma once
#include <core/Common.h>
#include <glad/glad.h>
#include <core/Core.h>
namespace engine
{
    class Mesh
    {
    public:
        Mesh(const MeshData& meshData);
        void Draw() const;
    private:
        ui32 m_vao = 0;
        ui32 m_vbo = 0;
        ui32 m_ebo = 0;
        i32 m_count = 0;

        void initVertexArray();
        void initVertexBuffer(const float* vertices, size_t size);
        void initElementBuffer(const ui32* indices, size_t index_size);
        void linkVertexAttributes();
    };
    
}

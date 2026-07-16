#pragma once

#include <glad/glad.h>
#include <vector>
namespace otterus_rendering{
    struct MeshData {
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
    };
    class Mesh
    {
    public:
        Mesh(const MeshData& meshData);
        void Draw() const;
    private:
        unsigned int m_vao = 0;
        unsigned int m_vbo = 0;
        unsigned int m_ebo = 0;
        unsigned int m_count = 0;

        void initVertexArray();
        void initVertexBuffer(const float* vertices, size_t size);
        void initElementBuffer(const unsigned int* indices, size_t index_size);
        void linkVertexAttributes();
    };
    
}

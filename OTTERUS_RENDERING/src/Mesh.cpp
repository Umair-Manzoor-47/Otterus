
#include <Rendering/Essentials/Mesh.h>
#include <glad/glad.h>
namespace otterus_rendering
{
    Mesh::Mesh(const MeshData& data)
        : m_count(data.indices.size())
    {
        initVertexArray();

        initVertexBuffer(
            data.vertices.data(),
            data.vertices.size() * sizeof(float)
        );

        initElementBuffer(
            data.indices.data(),
            data.indices.size()
        );

        linkVertexAttributes();
    }
    void Mesh::initVertexArray() {
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);
    }

    void Mesh::initVertexBuffer(const float* vertices, size_t size) {
        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    void Mesh::initElementBuffer(const unsigned int* indices, size_t index_size) {
        glGenBuffers(1, &m_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_size * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    }

    /// Here is map of linking vertex attributes
    // argument 1: 0              → which attribute slot (location = 0 in vertex shader)
    // argument 2: 3              → how many values this attribute has (x, y, z = 3)
    // argument 3: GL_FLOAT       → what type each value is
    // argument 4: GL_FALSE       → don't normalize
    // argument 5: 3 * sizeof(float) → STRIDE: total bytes per vertex (jump this much to get to next vertex)
    // argument 6: (void*)0       → OFFSET: where does this attribute start within the vertex (0 = beginning)
    void Mesh::linkVertexAttributes() {
        // position — location 0
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // normal — location 1
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
            8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // texture coords — location 2
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
            8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }


    void Mesh::Draw() const {
        glBindVertexArray(m_vao);
        glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, 0);
    }
}

#include <graphics/Mesh.h>

void engine::Mesh::initVertexArray() {
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);
}

void engine::Mesh::initVertexBuffer(float vertices[], size_t size) {
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void engine::Mesh::initElementBuffer(ui32 indices[], size_t index_size) {
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_size, indices, GL_STATIC_DRAW);
}
void engine::Mesh::linkVertexAttributes() {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
engine::Mesh::Mesh(const MeshDesc& desc): m_count(desc.index_size) {

    initVertexArray();
    initVertexBuffer(desc.vertices, desc.size);
    initElementBuffer(desc.indices, desc.index_size);
    linkVertexAttributes();

}

void engine::Mesh::Draw() {
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, 0);
}
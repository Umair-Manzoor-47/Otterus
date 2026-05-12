//
// Created by umair on 5/9/2026.
//
#include <iostream>
#include <ostream>
#include <graphics/GraphicsEngine.h>

#include <core/Logger.h>
#include <glad/glad.h>


void engine::GraphicsEngine::RunGraphicsProgram(float vertices[], size_t size, ui32 indices[], size_t index_size) {

    createVAO();
    initVertexBuffer(vertices, size);
    initElementBuffer(indices, index_size);
    linkVertexAttributes();

}
void engine::GraphicsEngine::SetShader(const ShaderDesc &desc) {
    m_shader.Load(desc);
}

void engine::GraphicsEngine::Draw() {
    m_shader.Bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



void engine::GraphicsEngine::initVertexBuffer(float vertices[], size_t size) {
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void engine::GraphicsEngine::initElementBuffer(ui32 indices[], size_t index_size) {
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_size, indices, GL_STATIC_DRAW);
}

void engine::GraphicsEngine::linkVertexAttributes() {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void engine::GraphicsEngine::createVAO() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
}

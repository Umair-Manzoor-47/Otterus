//
// Created by umair on 5/9/2026.
//
#include <iostream>
#include <ostream>
#include <graphics/GraphicsEngine.h>

#include <core/Logger.h>
#include <glad/glad.h>

void engine::GraphicsEngine::RunGraphicsProgram(float vertices[], size_t size, ui32 indices[], size_t index_size) {
    readShadersSources("../assets/shaders/vertex_shader.glsl", "../assets/shaders/fragment_shader.glsl");
    createVAO();
    initVertexBuffer(vertices, size);
    initElementBuffer(indices, index_size);
    createVertexShader();
    createFragmentShader();
    createShaderProgram();
    linkVertexAttributes();
    deletShaders();

}

void engine::GraphicsEngine::Draw() {
    glUseProgram(shaderProgram);
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

void engine::GraphicsEngine::createVertexShader() {
    const char* src = vertexShaderCode.c_str();
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // compile shader
    glShaderSource(vertexShader, 1, &src, NULL);
    glCompileShader(vertexShader);
    // failure checking
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LogError(infoLog);
    }
}

void engine::GraphicsEngine::createFragmentShader() {
    const char* src = fragmentShaderCode.c_str();
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &src, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        LogError(infoLog);
    }
}

void engine::GraphicsEngine::createShaderProgram() {
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        LogError(infoLog);
    }

}

void engine::GraphicsEngine::deletShaders() {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void engine::GraphicsEngine::linkVertexAttributes() {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void engine::GraphicsEngine::createVAO() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
}



void engine::GraphicsEngine::readShadersSources(const std::string&vertexShaderPath, const std::string&fragmentShaderPath) {
    vertexShaderCode = readFile(vertexShaderPath);
    fragmentShaderCode = readFile(fragmentShaderPath);

}

std::string engine::GraphicsEngine::readFile(const std::string &path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}
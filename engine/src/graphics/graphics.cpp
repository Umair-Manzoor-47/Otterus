//
// Created by umair on 5/9/2026.
//
#include <iostream>
#include <ostream>
#include <graphics/graphics.h>

#include "core/Logger.h"
#include "glad/glad.h"

const char* shaderDataSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";


void engine::graphics::initVertexBuffer(float vertices[]) {
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void engine::graphics::createVertexShader() {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // compile shader
    glShaderSource(vertexShader, 1, &shaderDataSource, NULL);
    glCompileShader(vertexShader);
    // failure checking
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LogError(infoLog);
    }
}

void engine::graphics::createFragmentShader() {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        LogError(infoLog);
    }
}

void engine::graphics::createShaderProgram() {
    shaderProgram = glCreateProgram();

    glAttachShader(vertexShader, shaderProgram);
    glAttachShader(fragmentShader, shaderProgram);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        LogError(infoLog);
    }

    glUseProgram(shaderProgram);
}

void engine::graphics::destroyVertexBuffer() {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void engine::graphics::linkVertexAttributes() {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

//
// Created by umair on 5/8/2026.
//

#include "Flores.h"
#include <core/Logger.h>
void Flores::OnStart() {
    LogInfo("Flores started.");    float vertices[] = {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       -0.5f,  0.5f, 0.0f
   };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    
    m_graphics_engine->SetShader({
        "../assets/shaders/vertex_shader.glsl",
        "../assets/shaders/fragment_shader.glsl"
      });
    m_graphics_engine->SetMesh({vertices, sizeof(vertices), indices, 6});

}

void Flores::OnUpdate() {
    m_graphics_engine->Draw();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Flores::OnShutdown() {
    LogInfo("Flores shutdown.");
}

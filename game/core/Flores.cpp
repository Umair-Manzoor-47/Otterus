//
// Created by umair on 5/8/2026.
//

#include "Flores.h"
#include <core/Logger.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <event/mouse/MouseMovedEvent.h>
#include <graphics/Transform.h>
#include <game_object/GameObject.h>

void Flores::OnStart() {
    std::unique_ptr<engine::GameObject> obj = std::make_unique<engine::GameObject>("Test", engine::TransformDesc{
    glm::vec3(0.f, 0.f, -3.f),
    glm::vec3(0.f),
    glm::vec3(1.f)
    });
    
    m_camera = std::make_unique<engine::Camera>();
    m_input = &GetContext().GetInputSystem();

    float vertices[] = {
        // x      y      z     nx    ny    nz    u     v
        0.5f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.5f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
       -0.5f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
       -0.5f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 0.0f, 1.0f
    };
    // light position
    
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    std::shared_ptr<engine::Shader> m_shader = std::make_shared<engine::Shader>();
    m_shader->Load({
        "../assets/shaders/vertex_shader.glsl",
        "../assets/shaders/fragment_shader.glsl"
      });
    obj->SetShader(m_shader);
    std::shared_ptr<engine::Mesh> m_mesh = std::make_shared<engine::Mesh>(engine::MeshDesc{vertices, sizeof(vertices), indices, 6});
    obj->SetMesh(m_mesh);
    std::shared_ptr<engine::Texture> m_texture = std::make_shared<engine::Texture>("../assets/container.jpg");
    obj->SetTexture(m_texture);
    
    GetContext().GetDispatcher().Subscribe<engine::MouseMovedEvent>([this](engine::MouseMovedEvent& e) {
    if (m_firstMouse) {
        m_lastMouseX = e.GetX();
        m_lastMouseY = e.GetY();
        m_firstMouse = false;
        return;
    }
    
    float offsetX = e.GetX() - m_lastMouseX;
    float offsetY = m_lastMouseY - e.GetY();
    
    m_lastMouseX = e.GetX();
    m_lastMouseY = e.GetY();
    
    float sensitivity = 0.1f;
    m_yaw   += offsetX * sensitivity;
    m_pitch += offsetY * sensitivity;
    
    m_camera->SetRotation(m_yaw, m_pitch);
    });
    
    auto obj2 = std::make_unique<engine::GameObject>("Test2", engine::TransformDesc{
    glm::vec3(2.f, 0.f, -3.f),  // offset position
    glm::vec3(0.f),
    glm::vec3(1.f)
});
    // share same mesh/shader/texture
    obj2->SetShader(m_shader);
    obj2->SetMesh(m_mesh);
    obj2->SetTexture(m_texture);

    m_scene = std::make_unique<engine::Scene>();
    m_scene->AddObject(std::move(obj));
    m_scene->AddObject(std::move(obj2));
}

void Flores::OnUpdate(float deltaTime)
{

    float speed = 5.f;
    
    if (m_input->IsKeyHeld(GLFW_KEY_W))
    {
        // move forward
        m_camera->SetPosition(m_camera->GetPosition() + m_camera->GetForward() * speed * deltaTime);
        
    }
    if (m_input->IsKeyHeld(GLFW_KEY_S))
    {
        // move backward
        m_camera->SetPosition(m_camera->GetPosition() - m_camera->GetForward() * speed * deltaTime);
        
    }
    if (m_input->IsKeyHeld(GLFW_KEY_A))
    {
        // move left
        m_camera->SetPosition(m_camera->GetPosition() - m_camera->GetRightVector() * speed * deltaTime);
    }
    if (m_input->IsKeyHeld(GLFW_KEY_D))
    {
        // move right
        m_camera->SetPosition(m_camera->GetPosition() + m_camera->GetRightVector() * speed * deltaTime);
        
    }
    engine::GameObject* obj = m_scene->GetObject("Test");
    if (obj) {
        obj->GetTransform().SetRotation(
            glm::vec3(0.f, glfwGetTime() * 50.f, 0.f)
        );
    }
}

void Flores::OnShutdown() {
    LogInfo("Flores shutdown.");
}

void Flores::OnRender()
{   glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    engine::RenderLight light;
    light.position = glm::vec3(1.2f, 1.0f, 2.0f);
    light.color = glm::vec3(1.0f);
    m_scene->Render(GetContext().GetGraphicsEngine(), m_camera->GetRenderCamera(), light);
}

engine::WindowDesc Flores::GetWindowDesc()
{
   return engine::WindowDesc{
        800,
        600,
        "Otterus"
    };
    
}
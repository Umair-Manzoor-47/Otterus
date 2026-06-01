//
// Created by umair on 5/8/2026.
//

#include "Flores.h"
#include <core/Logger.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <event/mouse/MouseMovedEvent.h>
#include <graphics/Transform.h>
#include <game_object/GameObject.h>
#include <graphics/MeshLoader.h>
#include <graphics/Material.h>
#include <resource_manager/ResourceManager.h>

Flores::Flores() {}

void Flores::OnStart() {

    OT_INFO("Flores Start.");
    m_resourceManager = std::make_unique<engine::ResourceManager>();
    std::unique_ptr<engine::GameObject> obj = std::make_unique<engine::GameObject>("Test", engine::TransformDesc{
    glm::vec3(0.f, 0.f, -3.f),
    glm::vec3(0.f),
    glm::vec3(1.f)
    });
    
    m_camera = std::make_unique<engine::Camera>();
    m_input = &GetContext().GetInputSystem();

    
    const std::shared_ptr<engine::Shader> m_shader = m_resourceManager->LoadShader( "../assets/shaders/vertex_shader.glsl",
        "../assets/shaders/fragment_shader.glsl");
    obj->SetShader(m_shader);
    auto meshData = engine::MeshLoader::Load("../assets/cube/Cube.obj");
    auto m_mesh = m_resourceManager->Load<engine::Mesh>("../assets/cube/Cube.obj");
    obj->SetMesh(m_mesh);
    
    
    obj->SetMaterial(meshData.material);
    m_scene = std::make_unique<engine::Scene>();
    m_scene->AddObject(std::move(obj));
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
    // engine::GameObject* obj = m_scene->GetObject("Test");
    // if (obj) {
    //     obj->GetTransform().SetRotation(
    //         glm::vec3(0.f, glfwGetTime() * 50.f, 0.f)
    //     );
    // }
}

void Flores::OnShutdown() {
    OT_INFO("Flores shutdown.");
}

void Flores::OnRender()
{   glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    engine::RenderLight light;
    light.position = glm::vec3(1.2f, 1.0f, 2.0f);
    light.color = glm::vec3(1.0f);
    m_scene->Render(GetContext().GetGraphicsEngine(), m_camera->GetRenderCamera(), light);
}

void Flores::SetEngineContext(engine::EngineContext* context)
{
    m_engineContext = context;
}
//
// Created by umair on 5/8/2026.
//

#include "Flores.h"
#include <core/Logger.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <event/keyboard/KeyReleasedEvent.h>
#include <event/mouse/MouseButtonPressedEvent.h>
#include <event/mouse/MouseButtonReleasedEvent.h>
#include <event/mouse/MouseMovedEvent.h>
#include <event/mouse/MouseScrolledEvent.h>
#include <event/window/WindowResizeEvent.h>
#include <graphics/Transform.h>

void Flores::OnStart() {
    m_camera = std::make_unique<engine::Camera>();
    m_input = &GetContext().GetInputSystem();
    m_gfx   = &GetContext().GetGraphicsEngine();
    float vertices[] = {
        //   x      y     z     u     v
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
   };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    m_transform = std::make_unique<engine::Transform>(engine::TransformDesc{
    glm::vec3(0.f, 0.f, -3.f),  // position
    glm::vec3(0.f),               // rotation
    glm::vec3(1.f)                // scale
    });
    m_gfx->SetShader({
        "../assets/shaders/vertex_shader.glsl",
        "../assets/shaders/fragment_shader.glsl"
      });
    m_gfx->SetMesh({vertices, sizeof(vertices), indices, 6});
    m_gfx->SetTexture({"../assets/container.jpg"});
    // m_dispatcher.Subscribe<engine::KeyPressedEvent>([this](engine::KeyPressedEvent& e) {
    //     std::string msg = "Key pressed: " + std::to_string(e.GetKeyCode());
    //     LogInfo(msg.c_str());
    // });

    // m_dispatcher.Subscribe<engine::KeyReleasedEvent>([this](engine::KeyReleasedEvent& e) {
    //     std::string msg = "Key released: " + std::to_string(e.GetKeyCode());
    //     LogInfo(msg.c_str());
    // });
    
    // m_dispatcher.Subscribe<engine::MouseMovedEvent>([this](engine::MouseMovedEvent& e)
    // {
    //     std::string msg = "Mouse Moved: " + std::to_string(e.GetX()) + ", " + std::to_string(e.GetY());
    //     LogInfo(msg.c_str());
    // });
    // m_dispatcher.Subscribe<engine::MouseButtonPressedEvent>([this](engine::MouseButtonPressedEvent& e)
    // {
    //     std::string msg = "Mouse Button Pressed: " + std::to_string(e.GetButton());
    //     LogInfo(msg.c_str());
    // });
    // m_dispatcher.Subscribe<engine::MouseButtonReleasedEvent>([this](engine::MouseButtonReleasedEvent& e)
    // {
    //     std::string msg = "Mouse Button Released: " + std::to_string(e.GetButton());
    //     LogInfo(msg.c_str());
    // });
    // m_dispatcher.Subscribe<engine::MouseScrolledEvent>([this](engine::MouseScrolledEvent& e)
    // {
    //     std::string msg = "Mouse Scrolled Event: " + std::to_string(e.GetYOffset());
    //     LogInfo(msg.c_str());
    // });
    //
    // m_dispatcher.Subscribe<engine::WindowResizeEvent>([this](engine::WindowResizeEvent& e)
    // {
    //     std::string msg = "Window Resized: " + std::to_string(e.GetWidth());
    //     LogInfo(msg.c_str());
    // });
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
    m_transform->SetRotation(glm::vec3(0.f, glfwGetTime() * 50.f, 0.f));
}

void Flores::OnShutdown() {
    LogInfo("Flores shutdown.");
}

void Flores::OnRender()
{   glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    GetContext().GetGraphicsEngine().Draw(
        m_camera->GetProjectionMatrix(),
        m_camera->GetViewMatrix(), 
        m_transform->GetModelMatrix());
}

engine::WindowDesc Flores::GetWindowDesc()
{
   return engine::WindowDesc{
        800,
        600,
        "Otterus"
    };
    
}
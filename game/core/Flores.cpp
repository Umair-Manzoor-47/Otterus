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

void Flores::OnStart() {
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
    
    m_graphics_engine->SetShader({
        "../assets/shaders/vertex_shader.glsl",
        "../assets/shaders/fragment_shader.glsl"
      });
    m_graphics_engine->SetMesh({vertices, sizeof(vertices), indices, 6});
    m_graphics_engine->SetTexture({"../assets/container.jpg"});
    m_dispatcher.Subscribe<engine::KeyPressedEvent>([this](engine::KeyPressedEvent& e) {
        std::string msg = "Key pressed: " + std::to_string(e.GetKeyCode());
        LogInfo(msg.c_str());
    });

    m_dispatcher.Subscribe<engine::KeyReleasedEvent>([this](engine::KeyReleasedEvent& e) {
        std::string msg = "Key released: " + std::to_string(e.GetKeyCode());
        LogInfo(msg.c_str());
    });
    
    // m_dispatcher.Subscribe<engine::MouseMovedEvent>([this](engine::MouseMovedEvent& e)
    // {
    //     std::string msg = "Mouse Moved: " + std::to_string(e.GetX()) + ", " + std::to_string(e.GetY());
    //     LogInfo(msg.c_str());
    // });
    m_dispatcher.Subscribe<engine::MouseButtonPressedEvent>([this](engine::MouseButtonPressedEvent& e)
    {
        std::string msg = "Mouse Button Pressed: " + std::to_string(e.GetButton());
        LogInfo(msg.c_str());
    });
    m_dispatcher.Subscribe<engine::MouseButtonReleasedEvent>([this](engine::MouseButtonReleasedEvent& e)
    {
        std::string msg = "Mouse Button Released: " + std::to_string(e.GetButton());
        LogInfo(msg.c_str());
    });
    m_dispatcher.Subscribe<engine::MouseScrolledEvent>([this](engine::MouseScrolledEvent& e)
    {
        std::string msg = "Mouse Scrolled Event: " + std::to_string(e.GetYOffset());
        LogInfo(msg.c_str());
    });
    
    m_dispatcher.Subscribe<engine::WindowResizeEvent>([this](engine::WindowResizeEvent& e)
    {
        std::string msg = "Window Resized: " + std::to_string(e.GetWidth());
        LogInfo(msg.c_str());
    });
}

void Flores::OnUpdate() {}

void Flores::OnShutdown() {
    LogInfo("Flores shutdown.");
}

void Flores::OnRender()
{   glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    m_graphics_engine->Draw(m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
}

engine::WindowDesc Flores::GetWindowDesc()
{
   return engine::WindowDesc{
        800,
        600,
        "Otterus"
    };
    
}
//
// Created by umair on 5/8/2026.
//
#pragma once

#include <entrypoint/Application.h>
#include <core/Core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <graphics/Transform.h>
#include <scene/Scene.h>

class Flores : public engine::Application {
public:
    void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnShutdown() override;
    void OnRender() override;
    engine::WindowDesc GetWindowDesc() override;
    
private:
    engine::InputSystem* m_input = nullptr;
    engine::GraphicsEngine* m_gfx = nullptr;
    std::unique_ptr<engine::Camera> m_camera;
    float m_lastMouseX = 400.f;
    float m_lastMouseY = 300.f;
    float m_yaw   = -90.f;
    float m_pitch = 0.f;
    bool m_firstMouse = true;
    std::unique_ptr<engine::Scene> m_scene;
};

//
// Created by umair on 5/8/2026.
//
#pragma once

#include <entrypoint/Application.h>
#include <scene/Scene.h>
#include <IGame.h>
#include <Core/Resources/AssetManager.h>

class Flores : public editor::IGame {
public:
    Flores();
    void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnShutdown() override;
    void OnRender() override;

    engine::Scene* GetScene() override { return m_scene.get(); }
    
private:
    std::unique_ptr<otterus_resources::AssetManager> m_resourceManager;
    std::shared_ptr<otterus::windowing::input::InputSystem> m_input = nullptr;
    otterus_rendering::GraphicsEngine* m_gfx = nullptr;
    std::shared_ptr<otterus_rendering::Camera> m_camera;
    float m_lastMouseX = 400.f;
    float m_lastMouseY = 300.f;
    float m_yaw   = -90.f;
    float m_pitch = 0.f;
    bool m_firstMouse = true;
    std::unique_ptr<engine::Scene> m_scene;
};

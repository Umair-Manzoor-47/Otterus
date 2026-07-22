#include "Flores.h"
#include <logger/Logger.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <event/mouse/MouseMovedEvent.h>
#include <Rendering/Essentials/MeshLoader.h>
#include <Core/Resources/AssetManager.h>
#include <ECS/Entity.h>
#include <Input/InputSystem.h>
#include <Core/Systems/TransformSystem.h>
#include "ECS/Components/TransformComponent.h"
Flores::Flores() {}

void Flores::OnStart() {

    OT_INFO("Flores Start.");
    // Systems
    auto m_assetManager = std::make_shared<otterus_resources::AssetManager>();
    m_camera = std::make_shared<otterus_rendering::Camera>();
    m_input = m_registry->GetContext<std::shared_ptr<otterus::windowing::input::InputSystem>>();

    if (!m_registry->AddToContext<std::shared_ptr<otterus_resources::AssetManager>>(m_assetManager)) {
        OT_ERROR("Failed to add AssetManager into registry context.");
        return;
    }

    if (!m_registry->AddToContext<std::shared_ptr<otterus_rendering::Camera>>(m_camera)) {
        OT_ERROR("Failed to add Camera2D into registry context.");
        return;
    }

    // Resources
    const std::shared_ptr<otterus_rendering::Shader> m_shader = m_assetManager->LoadShader( "../game/assets/shaders/vertex_shader.glsl",
        "../game/assets/shaders/fragment_shader.glsl");
    auto meshData = otterus_rendering::MeshLoader::Load("../game/assets/cube/Cube.obj");
    if (!m_assetManager->AddMesh("CubeMesh", "../game/assets/cube/Cube.obj")) {
        OT_ERROR("Failed to add mesh");
        return;
    }
    auto m_mesh = m_assetManager->GetMesh("CubeMesh");
    auto material = std::make_shared<otterus_rendering::Material>();
    if (!m_assetManager->AddTexture("cube", "../game/assets/cube/cube_texture.png")) {

        OT_INFO("Failed to Create texture");
    }
    auto texture = m_assetManager->GetTexture("cube");
    material->SetUseTexture(true);
    material->SetDiffuseTexture(texture);

    auto transformSystem  = std::make_shared<otterus_core::Systems::TransformSystem>();
    if (!m_registry->AddToContext<std::shared_ptr<otterus_core::Systems::TransformSystem>>(transformSystem)) {
        OT_ERROR("Failed to add TransformSystem into registry context.");
        return;
    }

    // Entities
    auto entity1 = std::make_shared<otterus_core::ECS::Entity>(*m_registry, "entity1", "test");
    entity1->AddComponent<otterus_core::ECS::TransformComponent>(otterus_core::ECS::TransformComponent{
        .position = {0.f, 0.f, 0.f},
        .scale = {1.f, 1.f, 1.f},
        .rotation = {0.f, 0.f, 0.f}
    });
    entity1->AddComponent<std::shared_ptr<otterus_rendering::Mesh>>(m_mesh);
    entity1->AddComponent<std::shared_ptr<otterus_rendering::Shader>>(m_shader);
    entity1->AddComponent<std::shared_ptr<otterus_rendering::Material>>(material);
    m_scene = std::make_unique<engine::Scene>(*m_registry);
    m_scene->AddEntity(std::move(entity1));

    // Events
    auto dispatcher = m_registry->GetContext<std::shared_ptr<otterus::windowing::event::Dispatcher>>();
    dispatcher->Subscribe<otterus::windowing::event::MouseMovedEvent>([this](otterus::windowing::event::MouseMovedEvent& e) {
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
    otterus_core::ECS::Entity* entity = m_scene->GetEntity("entity1");
    if (entity) {
        auto& transform = entity->GetComponent<otterus_core::ECS::TransformComponent>();
        transform.rotation = glm::vec3(0.f, glfwGetTime() * 50.f, 0.f);
        transform.dirty = true;
    }
}

void Flores::OnShutdown() {
    OT_INFO("Flores shutdown.");
}

void Flores::OnRender()
{
    otterus_rendering::RenderLight light;
    light.position = glm::vec3(1.2f, 1.0f, 2.0f);
    light.color = glm::vec3(1.0f);
    auto graphicsEngine = m_registry->GetContext<std::shared_ptr<otterus_rendering::GraphicsEngine>>();
    m_scene->Render(*graphicsEngine, m_camera->GetRenderCamera(), light);
}

void Flores::Initialize(otterus_core::ECS::Registry& registry)
{
    m_registry = &registry;
}

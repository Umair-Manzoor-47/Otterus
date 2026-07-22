#include <scene/Scene.h>
#include <entt/entt.hpp>
#include <ECS/Components/TransformComponent.h>
#include <ECS/Registry.h>

#include <Core/Systems/TransformSystem.h>

engine::Scene::Scene(otterus_core::ECS::Registry& registry):
m_registry(registry)
{}

void engine::Scene::AddEntity(std::shared_ptr<otterus_core::ECS::Entity> entity){
	m_entities.push_back(std::move(entity));
}

void engine::Scene::RemoveEntity(const std::string& name){
m_entities.erase(
        std::remove_if(
            m_entities.begin(),
            m_entities.end(),
            [&](const std::shared_ptr<otterus_core::ECS::Entity>& entity)
            {
                return entity->GetName() == name;
            }),
        m_entities.end());
}


otterus_core::ECS::Entity* engine::Scene::GetEntity(const std::string& name)
{
    for (const auto& entity : m_entities)
    {
        if (entity->GetName() == name)
        {
            return entity.get();
        }
    }

    return nullptr;
}

void engine::Scene::Render(otterus_rendering::GraphicsEngine& gfx, const otterus_rendering::RenderCamera& renderCamera, const otterus_rendering::RenderLight& light) {

    for (auto& entity : m_entities) {
        if (!entity->HasComponent<std::shared_ptr<otterus_rendering::Mesh>>() || !entity->HasComponent<std::shared_ptr<otterus_rendering::Shader>>())
            continue;
        auto transform = entity->GetComponent<otterus_core::ECS::TransformComponent>();
        auto transformSystem = m_registry.GetContext<std::shared_ptr<otterus_core::Systems::TransformSystem>>();
        transformSystem->Update(m_registry.GetRegistry());
        gfx.Draw(
            *entity->GetComponent<std::shared_ptr<otterus_rendering::Mesh>>(),
            *entity->GetComponent<std::shared_ptr<otterus_rendering::Shader>>(),
            entity->GetComponent<std::shared_ptr<otterus_rendering::Material>>().get(),
            renderCamera,
            light,
            transform.modelMatrix
            );
    }
}
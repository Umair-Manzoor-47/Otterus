#pragma once
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <Rendering/Core/GraphicsEngine.h>
#include <Rendering/Core/Camera.h>
#include <Ecs/Registry.h>
#include <ECS/Entity.h>

namespace engine
{
    class Scene
    {
    public:
        Scene(otterus_core::ECS::Registry& registry);
        void AddEntity(std::shared_ptr<otterus_core::ECS::Entity> entity);
        void RemoveEntity(const std::string& name);
        void Render(otterus_rendering::GraphicsEngine& gfx, const otterus_rendering::RenderCamera& renderCamera, const otterus_rendering::RenderLight& light);


        otterus_core::ECS::Entity* GetEntity(const std::string& name);
        const std::vector<std::shared_ptr<otterus_core::ECS::Entity>>& GetEntities() const {return m_entities;}

    private:
        std::vector<std::shared_ptr<otterus_core::ECS::Entity>> m_entities;
        otterus_core::ECS::Registry& m_registry;
    
    };
    
}

#pragma once

#include <entt/entt.hpp>
#include <ECS/Components/TransformComponent.h>

namespace otterus_core::Systems
{
    class TransformSystem
    {
    public:
        static void Update(entt::registry& registry);

    private:
        static glm::mat4 BuildModelMatrix(const ECS::TransformComponent& transform);
    };
}
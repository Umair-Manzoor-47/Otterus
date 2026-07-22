#include <Core/Systems/TransformSystem.h>

#include <glm/gtc/matrix_transform.hpp>

#include <ECS/Components/TransformComponent.h>

namespace otterus_core::Systems
{

    void TransformSystem::Update(entt::registry& registry)
    {
        auto view = registry.view<ECS::TransformComponent>();

        for (auto entity : view)
        {
            auto& transform = view.get<ECS::TransformComponent>(entity);

            if (!transform.dirty)
                continue;

            transform.modelMatrix = BuildModelMatrix(transform);
            transform.dirty = false;
        }
    }


    glm::mat4 TransformSystem::BuildModelMatrix(
        const ECS::TransformComponent& transform)
    {
        glm::mat4 model{1.0f};

        // Translation
        model = glm::translate(model, transform.position);

        // Rotation (Euler XYZ)
        model = glm::rotate(
            model,
            glm::radians(transform.rotation.x),
            glm::vec3(1.0f, 0.0f, 0.0f)
        );

        model = glm::rotate(
            model,
            glm::radians(transform.rotation.y),
            glm::vec3(0.0f, 1.0f, 0.0f)
        );

        model = glm::rotate(
            model,
            glm::radians(transform.rotation.z),
            glm::vec3(0.0f, 0.0f, 1.0f)
        );

        // Scale
        model = glm::scale(model, transform.scale);

        return model;
    }

}
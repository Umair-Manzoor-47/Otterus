#pragma once
#include <glm/glm.hpp>

namespace otterus_core::ECS {

    struct TransformComponent {

        glm::vec3 position{ glm::vec3{0.f} };
        glm::vec3 scale{ glm::vec3{1.f} };
        glm::vec3 rotation{ 0.f };

    };

}
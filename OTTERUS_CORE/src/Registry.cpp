#include <ECS/Registry.h>
#include <entt/entt.hpp>

#include <memory>


otterus_core::ECS::Registry::Registry() :
    m_registry{nullptr}
{
    m_registry = std::make_unique<entt::registry>();
}

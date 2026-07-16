#pragma once
#include <core/Common.h>
#include <core/Core.h>
#include <string>
#include <Rendering/Essentials/Mesh.h>
#include <Rendering/Essentials/Shader.h>
#include <Rendering/Essentials/Texture.h>
#include <Rendering/Essentials/Transform.h>
#include <Rendering/Essentials/Material.h>

namespace engine {
    class GameObject {
    public:
        GameObject(const std::string& name, const otterus_rendering::TransformDesc& transformDesc);

        void SetMesh(std::shared_ptr<otterus_rendering::Mesh> mesh);
        void SetShader(std::shared_ptr<otterus_rendering::Shader> shader);
        void SetMaterial(std::shared_ptr<otterus_rendering::Material> material);
        
        otterus_rendering::Transform& GetTransform() { return m_transform; }
        const otterus_rendering::Transform& GetTransform() const { return m_transform; }
        std::shared_ptr<otterus_rendering::Mesh> GetMesh() const { return m_mesh; }
        std::shared_ptr<otterus_rendering::Shader> GetShader() const { return m_shader; }
        std::shared_ptr<otterus_rendering::Material> GetMaterial() const { return m_material; }
        const std::string& GetName() const { return m_name; }
        
        bool HasMesh() const { return m_mesh != nullptr; }
        bool HasShader() const { return m_shader != nullptr; }
        bool HasMaterial() const { return m_material != nullptr; }

    private:
        std::string m_name;
        otterus_rendering::Transform m_transform;
        std::shared_ptr<otterus_rendering::Mesh> m_mesh;
        std::shared_ptr<otterus_rendering::Shader> m_shader;
        std::shared_ptr<otterus_rendering::Material> m_material;
    };
}

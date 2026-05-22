#pragma once
#include <core/Common.h>
#include <core/Core.h>
#include <string>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/Texture.h>
#include <graphics/Transform.h>
#include <graphics/Material.h>

namespace engine {
    class GameObject {
    public:
        GameObject(const std::string& name, const TransformDesc& transformDesc);

        void SetMesh(std::shared_ptr<Mesh> mesh);
        void SetShader(std::shared_ptr<Shader> shader);
        void SetMaterial(std::shared_ptr<Material> material);
        
        Transform& GetTransform() { return m_transform; }
        const Transform& GetTransform() const { return m_transform; }
        std::shared_ptr<Mesh> GetMesh() const { return m_mesh; }
        std::shared_ptr<Shader> GetShader() const { return m_shader; }
        std::shared_ptr<Material> GetMaterial() const { return m_material; }
        const std::string& GetName() const { return m_name; }
        
        bool HasMesh() const { return m_mesh != nullptr; }
        bool HasShader() const { return m_shader != nullptr; }
        bool HasMaterial() const { return m_material != nullptr; }

    private:
        std::string m_name;
        Transform m_transform;
        std::shared_ptr<Mesh> m_mesh;
        std::shared_ptr<Shader> m_shader;
        std::shared_ptr<Material> m_material;
    };
}

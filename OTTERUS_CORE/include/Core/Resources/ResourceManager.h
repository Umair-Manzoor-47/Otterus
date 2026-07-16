#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <Rendering/Essentials/Texture.h>
#include <Rendering/Essentials/Mesh.h>
#include <Rendering/Essentials/Shader.h>

namespace otterus_resources {
    class ResourceManager {
    public:
        template<typename T>
        std::shared_ptr<T> Load(const std::string& path);
        void Clear();

        std::shared_ptr<otterus_rendering::Shader> LoadShader(const std::string &vertexPath, const std::string &fragmentPath);

        template<typename T>
        bool Exists(const std::string& path);

        template<typename T>
        void Unload(const std::string& path);

        size_t GetTextureCount() const { return m_textures.size(); }
        size_t GetMeshCount()    const { return m_meshes.size(); }
        size_t GetShaderCount()  const { return m_shaders.size(); }
    private:
        std::unordered_map<std::string, std::shared_ptr<otterus_rendering::Texture>> m_textures;
        std::unordered_map<std::string, std::shared_ptr<otterus_rendering::Mesh>> m_meshes;
        std::unordered_map<std::string, std::shared_ptr<otterus_rendering::Shader>> m_shaders;
        
    };
}
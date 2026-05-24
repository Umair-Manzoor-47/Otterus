#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <graphics/Texture.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshLoader.h>

namespace engine {
    class ResourceManager {
    public:
        template<typename T>
        std::shared_ptr<T> Load(const std::string& path);
        void Clear();

        std::shared_ptr<engine::Shader> LoadShader(const std::string &vertexPath, const std::string &fragmentPath);

        template<typename T>
        bool Exists(const std::string& path);

        template<typename T>
        void Unload(const std::string& path);

        size_t GetTextureCount() const { return m_textures.size(); }
        size_t GetMeshCount()    const { return m_meshes.size(); }
        size_t GetShaderCount()  const { return m_shaders.size(); }
    private:
        std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
        std::unordered_map<std::string, std::shared_ptr<Mesh>> m_meshes;
        std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaders;
        
    };
}
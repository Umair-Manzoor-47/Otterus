//
// Created by Umair Manzoor on 5/23/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <Core/Resources/ResourceManager.h>
#include <logger/Logger.h>
#include <Rendering/Essentials/TextureLoader.h>
#include <Rendering/Essentials/ShaderLoader.h>
#include <Rendering/Essentials/MeshLoader.h>


namespace otterus_resources
{
    /// <summary>
    /// Check if requested file already loaded and exists --> return it
    /// If it doesn't exist already load it --> Save it --> return it
    /// </summary>
    template<>
    std::shared_ptr<otterus_rendering::Texture> ResourceManager::Load<otterus_rendering::Texture>(const std::string& path)
    {
        if (auto it = m_textures.find(path); it != m_textures.end())
        {
            return it->second;
        }
        otterus_rendering::TextureData textureData = otterus_rendering::TextureLoader::Load(path);
        auto texture = std::make_shared<otterus_rendering::Texture>(textureData);

        m_textures[path] = texture;
        otterus_rendering::TextureLoader::Free(textureData);
        return texture;
    }

    template<>
    std::shared_ptr<otterus_rendering::Mesh> ResourceManager::Load<otterus_rendering::Mesh>(const std::string& path)
    {
        if (path.empty()) {
            CORE_ERROR("ResourceManager: empty path provided");
            return nullptr;
        }
        if (auto mt = m_meshes.find(path); mt != m_meshes.end())
        {
            return mt->second;
        }
        auto meshData = otterus_rendering::MeshLoader::Load(path);
        auto mesh = std::make_shared<otterus_rendering::Mesh>(meshData);

        m_meshes[path] = mesh;
        return mesh;
    }

    std::shared_ptr<otterus_rendering::Shader> ResourceManager::LoadShader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        if (fragmentPath.empty() || vertexPath.empty()) {
            CORE_ERROR("ResourceManager: empty path provided");
            return nullptr;
        }
        std::string key = vertexPath + "|" + fragmentPath;

        if (auto it = m_shaders.find(key); it != m_shaders.end())
            return it->second;

        auto shader = std::make_shared<otterus_rendering::Shader>();
        const otterus_rendering::ShaderSource shaderSource = otterus_rendering::ShaderLoader::Load({vertexPath, fragmentPath});
        shader->Load(shaderSource);

        m_shaders[key] = shader;
        return shader;
    }

    void ResourceManager::Clear() {
        m_textures.clear();
        m_meshes.clear();
        m_shaders.clear();
    }

    template<>
    bool ResourceManager::Exists<otterus_rendering::Texture>(const std::string& path) {
        return m_textures.find(path) != m_textures.end();
    }

    template<>
    bool ResourceManager::Exists<otterus_rendering::Mesh>(const std::string& path) {
        return m_meshes.find(path) != m_meshes.end();

    }
    template<>
    bool ResourceManager::Exists<otterus_rendering::Shader>(const std::string& path) {
        return m_shaders.find(path) != m_shaders.end();
    }

    template<>
    void ResourceManager::Unload<otterus_rendering::Mesh>(const std::string& path) {
        if (path.empty()) return;
        m_meshes.erase(path);
    }

    template<>
    void ResourceManager::Unload<otterus_rendering::Texture>(const std::string& path) {
        if (path.empty()) return;
        m_textures.erase(path);
    }

    template<>
    void ResourceManager::Unload<otterus_rendering::Shader>(const std::string& path) {
        if (path.empty()) return;
        m_shaders.erase(path);
    }
}
//
// Created by Umair Manzoor on 5/23/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <resource_manager/ResourceManager.h>

#include "core/Logger.h"
#include <loaders/TextureLoader.h>

/// <summary>
/// Check if requested file already loaded and exists --> return it
/// If it doesn't exist already load it --> Save it --> return it
/// </summary>
template<>
std::shared_ptr<engine::Texture> engine::ResourceManager::Load<engine::Texture>(const std::string& path)
{
    if (auto it = m_textures.find(path); it != m_textures.end())
    {
        return it->second;
    }
    TextureData textureData = TextureLoader::Load(path);
    auto texture = std::make_shared<engine::Texture>(textureData);

    m_textures[path] = texture;
    TextureLoader::Free(textureData);
    return texture;
}

template<>
std::shared_ptr<engine::Mesh> engine::ResourceManager::Load<engine::Mesh>(const std::string& path)
{
    if (path.empty()) {
        CORE_ERROR("ResourceManager: empty path provided");
        return nullptr;
    }
    if (auto mt = m_meshes.find(path); mt != m_meshes.end())
    {
        return mt->second;
    }
    auto meshData = MeshLoader::Load(path);
    auto mesh = std::make_shared<engine::Mesh>(meshData);

    m_meshes[path] = mesh;
    return mesh;
}

std::shared_ptr<engine::Shader> engine::ResourceManager::LoadShader(const std::string& vertexPath, const std::string& fragmentPath)
{
    if (fragmentPath.empty() || vertexPath.empty()) {
        CORE_ERROR("ResourceManager: empty path provided");
        return nullptr;
    }
    std::string key = vertexPath + "|" + fragmentPath;

    if (auto it = m_shaders.find(key); it != m_shaders.end())
        return it->second;

    auto shader = std::make_shared<Shader>();
    shader->Load({vertexPath, fragmentPath});

    m_shaders[key] = shader;
    return shader;
}

void engine::ResourceManager::Clear() {
    m_textures.clear();
    m_meshes.clear();
    m_shaders.clear();
}

template<>
bool engine::ResourceManager::Exists<engine::Texture>(const std::string& path) {
    return m_textures.find(path) != m_textures.end();
}

template<>
bool engine::ResourceManager::Exists<engine::Mesh>(const std::string& path) {
    return m_meshes.find(path) != m_meshes.end();

}
template<>
bool engine::ResourceManager::Exists<engine::Shader>(const std::string& path) {
    return m_shaders.find(path) != m_shaders.end();
}

template<>
void engine::ResourceManager::Unload<engine::Mesh>(const std::string& path) {
    if (path.empty()) return;
    m_meshes.erase(path);
}

template<>
void engine::ResourceManager::Unload<engine::Texture>(const std::string& path) {
    if (path.empty()) return;
    m_textures.erase(path);
}

template<>
void engine::ResourceManager::Unload<engine::Shader>(const std::string& path) {
    if (path.empty()) return;
    m_shaders.erase(path);
}
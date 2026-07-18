#include <Core/Resources/AssetManager.h>
#include <logger/Logger.h>
#include <Rendering/Essentials/TextureLoader.h>
#include <Rendering/Essentials/ShaderLoader.h>
#include <Rendering/Essentials/MeshLoader.h>


namespace otterus_resources
{

    bool AssetManager::AddMesh(const std::string& meshName, const std::string& path)
    {
        if (path.empty()) {
            CORE_ERROR("ResourceManager: empty path provided");
            return false;
        }
        if (auto mt = m_meshes.find(path); mt != m_meshes.end())
        {
            OT_INFO("Mesh already exists.");
            return false;
        }
        auto mesh = std::move(otterus_rendering::MeshLoader::Load(path));
        m_meshes.emplace(meshName, mesh);
        return true;
    }

    std::shared_ptr<otterus_rendering::Mesh> AssetManager::GetMesh(const std::string &meshName) {
        auto meshItr = m_meshes.find(meshName);
        if (meshItr == m_meshes.end()) {

            OT_ERROR("Failed to get mesh [{0}] -- Does not exist.", meshName);
            return nullptr;
        }

        return meshItr->second;
    }

    std::shared_ptr<otterus_rendering::Shader> AssetManager::LoadShader(const std::string& vertexPath, const std::string& fragmentPath)
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

    bool AssetManager::AddTexture(const std::string &textureName, const std::string &path) {
        if (auto it = m_textures.find(textureName); it != m_textures.end())
        {
            OT_ERROR("Texture already exists.");
            return false;
        }


        auto texture = std::move(otterus_rendering::TextureLoader::Load(path));
        if (!texture) {

            OT_INFO("Failed to load texture [{0}] -- At path {1}.", textureName, path);
            return false;
        }
        m_textures.emplace(textureName, std::move(texture));
        return true;
    }

    const otterus_rendering::Texture & AssetManager::GetTexture(const std::string &textureName) {
        auto texItr = m_textures.find(textureName);
        if (texItr == m_textures.end()) {

            OT_ERROR("Failed to get texture [{0}] -- Does not exist.", textureName);
            return otterus_rendering::Texture();
        }

        return *texItr->second;
    }

    void AssetManager::Clear() {
        m_textures.clear();
        m_meshes.clear();
        m_shaders.clear();
    }

}
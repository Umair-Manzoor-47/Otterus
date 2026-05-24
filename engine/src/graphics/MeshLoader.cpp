#include <graphics/MeshLoader.h>
#include <tiny_obj_loader.h>
#include <unordered_map>
#include <core/Logger.h>
#include <graphics/Material.h>

// Layout Produced
// [x y z nx ny nz u v]
engine::MeshData engine::MeshLoader::Load(const std::string& path)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warn;
    std::string err;
    std::string baseDir = path.substr(0, path.find_last_of("/\\") + 1);

    bool success = tinyobj::LoadObj(
        &attrib, &shapes, &materials,
        &warn, &err,
        path.c_str(), baseDir.c_str()
    );

    if (!warn.empty()) LogWarning(warn.c_str());
    if (!err.empty())  LogError(err.c_str());
    if (!success)      LogError("Failed to load OBJ");

    MeshData meshData;
    std::unordered_map<std::string, ui32> uniqueVertices;

    for (const auto& shape : shapes)
    {
        for (const auto& index : shape.mesh.indices)
        {
            float px = attrib.vertices[3 * index.vertex_index + 0];
            float py = attrib.vertices[3 * index.vertex_index + 1];
            float pz = attrib.vertices[3 * index.vertex_index + 2];

            float nx = 0.f, ny = 0.f, nz = 0.f;
            if (index.normal_index >= 0)
            {
                nx = attrib.normals[3 * index.normal_index + 0];
                ny = attrib.normals[3 * index.normal_index + 1];
                nz = attrib.normals[3 * index.normal_index + 2];
            }

            float u = 0.f, v = 0.f;
            if (index.texcoord_index >= 0)
            {
                u = attrib.texcoords[2 * index.texcoord_index + 0];
                v = attrib.texcoords[2 * index.texcoord_index + 1];
            }

            std::string key = std::to_string(index.vertex_index) + "," +
                              std::to_string(index.normal_index)  + "," +
                              std::to_string(index.texcoord_index);

            if (uniqueVertices.count(key) == 0)
            {
                uniqueVertices[key] = static_cast<ui32>(meshData.vertices.size() / 8);

                meshData.vertices.push_back(px);
                meshData.vertices.push_back(py);
                meshData.vertices.push_back(pz);
                meshData.vertices.push_back(nx);
                meshData.vertices.push_back(ny);
                meshData.vertices.push_back(nz);
                meshData.vertices.push_back(u);
                meshData.vertices.push_back(v);
            }

            meshData.indices.push_back(uniqueVertices[key]);
        }
    }

    meshData.material = std::make_shared<Material>();
    if (!materials.empty())
    {
        if (!materials[0].diffuse_texname.empty())
        {
            auto texture = std::make_shared<Texture>(baseDir + materials[0].diffuse_texname);
            meshData.material->SetDiffuseTexture(texture);
        }
        else
        {
            meshData.material->SetDiffuseColor(glm::vec3(
                materials[0].diffuse[0],
                materials[0].diffuse[1],
                materials[0].diffuse[2]
            ));
        }
    }

    return meshData;
}
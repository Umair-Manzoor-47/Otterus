#include <graphics/MeshLoader.h>
#include <tiny_obj_loader.h>
#include <unordered_map>
#include <core/Logger.h>

// Layout Produced
// [x y z nx ny nz u v]
engine::MeshData engine::MeshLoader::Load(const std::string& path)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warn;
    std::string err;

    bool success = tinyobj::LoadObj(
        &attrib,
        &shapes,
        &materials,
        &warn,
        &err,
        path.c_str()
    );

    if (!warn.empty())
        LogWarning(warn.c_str());

    if (!err.empty())
        LogError(err.c_str());

    if (!success)
        LogError("Failed to load OBJ");

    MeshData meshData;
    

    for (const auto& shape : shapes)
    {
        for (const auto& index : shape.mesh.indices)
        {
            // POSITION
            float px = attrib.vertices[3 * index.vertex_index + 0];
            float py = attrib.vertices[3 * index.vertex_index + 1];
            float pz = attrib.vertices[3 * index.vertex_index + 2];

            // NORMAL
            float nx = 0.f;
            float ny = 0.f;
            float nz = 0.f;

            if (index.normal_index >= 0)
            {
                nx = attrib.normals[3 * index.normal_index + 0];
                ny = attrib.normals[3 * index.normal_index + 1];
                nz = attrib.normals[3 * index.normal_index + 2];
            }

            // UV
            float u = 0.f;
            float v = 0.f;

            if (index.texcoord_index >= 0)
            {
                u = attrib.texcoords[2 * index.texcoord_index + 0];
                v = attrib.texcoords[2 * index.texcoord_index + 1];
            }

            // PACK INTERLEAVED VERTEX
            meshData.vertices.push_back(px);
            meshData.vertices.push_back(py);
            meshData.vertices.push_back(pz);

            meshData.vertices.push_back(nx);
            meshData.vertices.push_back(ny);
            meshData.vertices.push_back(nz);

            meshData.vertices.push_back(u);
            meshData.vertices.push_back(v);

            meshData.indices.push_back(static_cast<ui32>(meshData.indices.size()));
        }
    }

    return meshData;
}

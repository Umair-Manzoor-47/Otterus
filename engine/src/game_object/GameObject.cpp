#include <game_object\GameObject.h>


engine::GameObject::GameObject(const std::string& name, const TransformDesc& transformDesc) :
m_name(name), 
m_transform(transformDesc){}

void engine::GameObject::SetMesh(std::shared_ptr<Mesh> mesh)
{
    m_mesh = mesh;
}

void engine::GameObject::SetShader(std::shared_ptr<Shader> shader)
{
    m_shader = shader;
}

void engine::GameObject::SetMaterial(std::shared_ptr<Material> material)
{
    m_material = material;
}
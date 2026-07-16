#include <scene/Scene.h>

void engine::Scene::AddObject(std::unique_ptr<GameObject> object){
	m_gameObjects.push_back(std::move(object));
}

void engine::Scene::RemoveObject(const std::string& name){
m_gameObjects.erase(
        std::remove_if(
            m_gameObjects.begin(),
            m_gameObjects.end(),
            [&](const std::unique_ptr<GameObject>& object)
            {
                return object->GetName() == name;
            }),
        m_gameObjects.end());
}


engine::GameObject* engine::Scene::GetObject(const std::string& name)
{
    for (const auto& object : m_gameObjects)
    {
        if (object->GetName() == name)
        {
            return object.get();
        }
    }

    return nullptr;
}

void engine::Scene::Render(otterus_rendering::GraphicsEngine& gfx, const otterus_rendering::RenderCamera& renderCamera, const otterus_rendering::RenderLight& light) {

    for (auto& object : m_gameObjects) {
        if (!object->HasMesh() || !object->HasShader())
            continue;
        
        gfx.Draw(
            *object->GetMesh(),
            *object->GetShader(),
            object->GetMaterial().get(),
            renderCamera,
            light,
            object->GetTransform().GetModelMatrix()
            );
    }
}
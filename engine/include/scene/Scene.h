#pragma once
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <game_object/GameObject.h>
#include <graphics/GraphicsEngine.h>
#include <camera/Camera.h>
#include <core/Common.h>
namespace engine
{
    class Scene
    {
    public:
        Scene() = default;
        void AddObject(std::unique_ptr<GameObject> object);
        void RemoveObject(const std::string& name);
        void Render(GraphicsEngine& gfx, const RenderCamera& renderCamera, const RenderLight& light);
        
        GameObject* GetObject(const std::string& name);
        const std::vector<std::unique_ptr<GameObject>>& GetObjects() const
        {
            return m_gameObjects;
        }
        
    private:
        std::vector<std::unique_ptr<GameObject>> m_gameObjects;
    
    };
    
}

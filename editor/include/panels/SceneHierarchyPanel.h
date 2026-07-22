#pragma once
#include <panels/Panel.h>
#include <scene/Scene.h>

namespace editor {
    class SceneHierarchyPanel : public Panel{

    public:
        explicit SceneHierarchyPanel(const std::string& title, engine::Scene* scene)
        : Panel(title), m_scene(scene) {};
        void OnRender() override;

    private:
        engine::Scene* m_scene;
        otterus_core::ECS::Entity* m_selectedObject = nullptr;

    };


} // editor

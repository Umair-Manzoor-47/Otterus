//
// Created by Umair Manzoor on 5/26/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

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
        engine::GameObject* m_selectedObject = nullptr;

    };


} // editor

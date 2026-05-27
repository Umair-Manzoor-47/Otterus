//
// Created by Umair Manzoor on 5/26/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <panels/SceneHierarchyPanel.h>

#include <imgui.h>

void editor::SceneHierarchyPanel::OnRender() {
    ImGui::SetNextWindowSize(ImVec2(300, 400), ImGuiCond_FirstUseEver);
    if (!ImGui::Begin(m_title.c_str())) {
        ImGui::End();
        return;
    }

    ImGui::Text("Hierarchy");
    ImGui::Separator();

    if (!m_scene)
    {
        ImGui::TextDisabled("No scene loaded.");
        ImGui::End();
        return;
    }

    const auto& objects = m_scene->GetObjects();
    ImGui::Text("Object count: %d", (int)objects.size());
    for (const auto& obj : objects) {
        if (!obj) continue;

        bool isSelected = (m_selectedObject == obj.get());
        if (ImGui::Selectable(obj->GetName().c_str(), isSelected)) {
            m_selectedObject = obj.get();
        }

    }

    ImGui::End();

}
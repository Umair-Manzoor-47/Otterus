//
// Created by Umair Manzoor on 5/24/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <Editor.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <core/Logger.h>
#include <panels/SceneHierarchyPanel.h>


void editor::Editor::OnStart() {
m_currentGame->OnStart();
    intializePanels();

}

void editor::Editor::OnUpdate(float deltaTime) {
    m_currentGame->OnUpdate(deltaTime);
}

void editor::Editor::OnRender() {
    m_currentGame->OnRender();
    m_sceneHierarchy->OnRender();

}

void editor::Editor::OnShutdown() {
    EndImGui();
    m_currentGame->OnShutdown();
}

void editor::Editor::BeginImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(GetContext().GetWindow().GetWindowHandle(), false);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void editor::Editor::EndImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void editor::Editor::intializePanels() {
    auto scene = m_currentGame->GetScene();
    m_sceneHierarchy = std::make_unique<SceneHierarchyPanel>("Scene Hierarchy", scene);
}

void editor::Editor::OnFrameBegin() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void editor::Editor::OnFrameEnd() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void editor::Editor::Init() {
    Application::Init();
    BeginImGui();
    m_currentGame->m_engineContext = &GetContext();



}

void editor::Editor::SetGame(std::unique_ptr<IGame> game) {
    m_currentGame = std::move(game);
}


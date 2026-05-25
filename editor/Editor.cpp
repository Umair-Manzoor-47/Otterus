//
// Created by Umair Manzoor on 5/24/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <Editor.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


void editor::Editor::OnStart() {
currentGame->OnStart();

}

void editor::Editor::OnUpdate(float deltaTime) {
    currentGame->OnUpdate(deltaTime);
}

void editor::Editor::OnRender() {
    currentGame->OnRender();
    ImGui::Begin("Scene");
    ImGui::Text("Scene Hierarchy");
    ImGui::End();

    ImGui::Begin("Properties");
    ImGui::Text("Select an object");
    ImGui::End();
}

void editor::Editor::OnShutdown() {
    EndImGui();
    currentGame->OnShutdown();
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
    currentGame->m_engineContext = &GetContext();


}

void editor::Editor::SetGame(std::unique_ptr<IGame> game) {
    currentGame = std::move(game);
}


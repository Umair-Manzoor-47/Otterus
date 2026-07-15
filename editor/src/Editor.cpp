//
// Created by Umair Manzoor on 5/24/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#include <Editor.h>
#include <imgui/imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <logger/Logger.h>
#include <panels/SceneHierarchyPanel.h>
#include <panels/ViewPortPanel.h>

engine::WindowDesc editor::Editor::GetWindowDesc()
{
    return engine::WindowDesc{1280, 720, "Otterus"};
}
void editor::Editor::OnStart() {
m_currentGame->OnStart();
    initializePanels();

}

void editor::Editor::OnUpdate(float deltaTime) {
    m_currentGame->OnUpdate(deltaTime);
}

void editor::Editor::OnRender() {
    m_frameBuffer->CheckResize();
    m_frameBuffer->Bind();
    glViewport(0, 0, m_frameBuffer->GetWidth(), m_frameBuffer->GetHeight());
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_currentGame->OnRender();
    m_frameBuffer->Unbind();
    
    m_sceneViewport->OnRender();
    m_sceneHierarchy->OnRender();
    ImGui::ShowDemoWindow();

}

void editor::Editor::OnShutdown() {
    EndImGui();
    m_currentGame->OnShutdown();
}

void editor::Editor::BeginImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(GetContext().GetWindow().GetWindowHandle(), true
        );
    ImGui_ImplOpenGL3_Init("#version 330");
    
    ImGuiIO& io = ImGui::GetIO();
    
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    
    io.ConfigWindowsMoveFromTitleBarOnly = true;
}

void editor::Editor::EndImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void editor::Editor::initializePanels() {
    auto scene = m_currentGame->GetScene();
    m_sceneHierarchy = std::make_unique<SceneHierarchyPanel>("Scene Hierarchy", scene);
    m_frameBuffer = std::make_shared<FrameBuffer>(640, 480, true);
    m_sceneViewport = std::make_unique<ViewPortPanel>("Scene Viewport", m_frameBuffer.get());
}

void editor::Editor::OnFrameBegin() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGuiID dockspace_id = ImGui::GetID("Otterus");
    ImGui::DockSpaceOverViewport(dockspace_id, ImGui::GetMainViewport());
}

void editor::Editor::OnFrameEnd() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();

        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();

        glfwMakeContextCurrent(backup_current_context);
    }
}

void editor::Editor::Init() {
    Application::Init();
    BeginImGui();
    m_currentGame->SetEngineContext(&GetContext());

}

void editor::Editor::SetGame(std::unique_ptr<IGame> game) {
    m_currentGame = std::move(game);
}


#include <panels/ViewPortPanel.h>

#include "imgui.h"

editor::ViewPortPanel::ViewPortPanel(const std::string &title, FrameBuffer *frameBuffer)
    : Panel(title),
    m_frameBuffer(frameBuffer)
{

}

void editor::ViewPortPanel::OnRender() {
    static bool open {true};

    if (!ImGui::Begin(m_title.c_str(), &open)) {
        ImGui::End();
        return;
    }
    if (ImGui::BeginChild("##SceneChild", ImVec2(0, 0), NULL, ImGuiWindowFlags_NoScrollWithMouse)) {
        ImGui::SetCursorPos(ImVec2(0.f, 0.f));

        ImVec2 viewportSize = ImGui::GetContentRegionAvail();  // available space in window

        // Resize if needed BEFORE rendering the image
        if ((int)viewportSize.x != m_frameBuffer->GetWidth() ||
            (int)viewportSize.y != m_frameBuffer->GetHeight()) {
            m_frameBuffer->Resize((int)viewportSize.x, (int)viewportSize.y);
            }

        ImGui::Image(
         (ImTextureID)m_frameBuffer->GetTextureID(),
            ImVec2{
            static_cast<float>(m_frameBuffer->GetWidth()),
            static_cast<float>(m_frameBuffer->GetHeight())
            },
        ImVec2(0.f, 1.f),
        ImVec2(1.f, 0.f)
        );
        ImGui::EndChild();

        // ImVec2 WindowSize{ImGui::GetWindowSize()};
        // if (m_frameBuffer->GetWidth() != static_cast<int>(WindowSize.x) || m_frameBuffer->GetHeight() != static_cast<int>(WindowSize.y)) {
        //     m_frameBuffer->Resize(static_cast<int>(WindowSize.x), static_cast<int>(WindowSize.y));
        // }
    }

    ImGui::End();

}

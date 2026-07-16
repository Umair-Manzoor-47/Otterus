//
// Created by Umair Manzoor on 5/24/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#pragma once
#include <entrypoint/Application.h>
#include <IGame.h>
#include <panels/Panel.h>
#include <Rendering/Buffers/FrameBuffer.h>

namespace editor {
    class Editor : public engine::Application {
    public:
        engine::WindowDesc GetWindowDesc() override;
        void OnStart() override;
        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnShutdown() override;
        void OnFrameBegin() override;
        void OnFrameEnd() override;

        void Init() override;

        void SetGame(std::unique_ptr<IGame> game);
    protected:
        void BeginImGui();
        void EndImGui();

    private:
        std::unique_ptr<IGame> m_currentGame;
        std::unique_ptr<Panel> m_sceneHierarchy;
        std::unique_ptr<Panel> m_sceneViewport;
        std::shared_ptr<otterus_rendering::FrameBuffer> m_frameBuffer;

        void initializePanels();
    };
} // editor

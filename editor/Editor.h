//
// Created by Umair Manzoor on 5/24/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#pragma once
#include <entrypoint/Application.h>
#include <IGame.h>

namespace editor {
    class Editor : public engine::Application {
    public:
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
        std::unique_ptr<IGame> currentGame;
    };
} // editor

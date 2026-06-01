//
// Created by Umair Manzoor on 5/25/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//


#pragma once
#include <scene/Scene.h>


namespace editor {
    class IGame {
    public:
        virtual ~IGame() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate(float dt) = 0;
        virtual void OnRender() = 0;
        virtual void OnShutdown() = 0;
        virtual engine::Scene *GetScene() = 0;
        virtual void SetEngineContext(engine::EngineContext* context) = 0;
        virtual engine::EngineContext& GetContext() = 0;

        friend class Editor;
    };
}
//
// Created by umair on 5/8/2026.
//
#pragma once
#include <Rendering/Core/Camera.h>
#include <core/Core.h>
#include <../../../OTTERUS_RENDERING/include/Rendering/Core/GraphicsEngine.h>
#include <event/Dispatcher.h>
#include <window/Window.h>
#include <input_system/InputSystem.h>
#include <engine_context/EngineContext.h>

namespace engine {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate(float deltaTime) = 0;
        virtual void OnShutdown() = 0;
        virtual void OnRender() = 0;
        virtual void OnFrameBegin() = 0;
        virtual void OnFrameEnd() = 0;
        virtual WindowDesc GetWindowDesc() {
            return WindowDesc{1920, 1080, "Otterus"};
        }


        virtual void Init();
        void Run();

    protected:
        bool m_Running = true;
        EngineContext& GetContext() { return *m_context; }

    private:
        std::unique_ptr<EngineContext> m_context;
        float m_lastTime = 0.f;
        
        float calculateDeltaTime();
    };


}

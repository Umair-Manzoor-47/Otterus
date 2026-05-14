//
// Created by umair on 5/8/2026.
//
#pragma once
#include <core/Core.h>
#include <graphics/GraphicsEngine.h>
#include <event/Dispatcher.h>
#include <window/Window.h>
#include <input_system/InputSystem.h>

namespace engine {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutdown() = 0;
        virtual void OnRender() = 0;
        virtual WindowDesc GetWindowDesc() = 0;


        void Init();
        void Run();

    protected:
        Dispatcher m_dispatcher{};
        std::unique_ptr<Window> m_window;
        std::unique_ptr<InputSystem> m_inputSystem;
        bool m_Running = true;
        std::unique_ptr<GraphicsEngine> m_graphics_engine;

    private:
        void CreateGraphicsEngine();
    };


}

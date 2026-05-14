//
// Created by umair on 5/8/2026.
//
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/Core.h>
#include <graphics/GraphicsEngine.h>
#include <event/Dispatcher.h>
#include <window/Window.h>
namespace engine {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutdown() = 0;


        void Init();
        void Run();

    protected:
        Dispatcher m_dispatcher{};
        std::unique_ptr<Window> m_window;
        bool m_Running = true;
        std::unique_ptr<GraphicsEngine> m_graphics_engine;

    private:
        void CreateGraphicsEngine();
    };


}

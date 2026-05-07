//
// Created by umair on 5/8/2026.
//
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace engine {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutdown() = 0;

        void Run();

    protected:
        bool m_Running = true;
        GLFWwindow* window = nullptr;

    private:
        void InitWindow();
        void UpdateWindow();
        void ShutdownWindow();
    };


}

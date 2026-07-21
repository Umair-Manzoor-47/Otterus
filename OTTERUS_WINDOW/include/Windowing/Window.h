#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <event/Dispatcher.h>
#include <functional>

#include <ECS/Registry.h>

namespace otterus::windowing::input {
    class InputSystem;
}
namespace otterus::windowing {
    struct WindowDesc {
        unsigned int width;
        unsigned int height;
        const char* title;
    };

    class Window {
    public:
        Window(const WindowDesc& desc, otterus_core::ECS::Registry& registry);
        void Init();
        void Update();
        void Destroy();
        GLFWwindow* GetWindowHandle() const { return m_handle; }
        event::Dispatcher& GetDispatcher() const { return *m_dispatcher; }

    private:
        GLFWwindow* m_handle = nullptr;
        std::shared_ptr<event::Dispatcher> m_dispatcher;
        unsigned int m_width;
        unsigned int m_height;
        const char* m_title;

        static void OnWindowClose(GLFWwindow* handle);
        static void OnWindowResize(GLFWwindow* handle, int width, int height);

    };
    struct WindowUserData {
        Window* window;
        input::InputSystem* input;
    };
}

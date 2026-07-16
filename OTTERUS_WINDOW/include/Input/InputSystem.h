#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace otterus::windowing::input {
    struct InputDesc {
        GLFWwindow* handle;
    };
    class InputSystem {

    public:
        explicit InputSystem(const InputDesc& desc);
        
        bool IsKeyHeld(int keyCode) const;
    private:
        static constexpr int MAX_KEYS = 512;
        bool m_keyStates[MAX_KEYS] = {false};
        
        static void KeyCallback(GLFWwindow* handle, int key, int scancode, int action, int mods);
        static void OnMouseMoved(GLFWwindow* handle, double x, double y);
        static void MouseButtonCallback(GLFWwindow* handle, int button, int action, int mods);
        static void ScrollCallback(GLFWwindow* handle, double x, double y);
    };
}


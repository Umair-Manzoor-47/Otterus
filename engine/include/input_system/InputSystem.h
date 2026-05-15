#pragma once
#include <core/Common.h>

namespace engine{
    class InputSystem {

    public:
        explicit InputSystem(const InputDesc& desc);
    private:

        static void KeyCallback(GLFWwindow* handle, int key, int scancode, int action, int mods);
        static void OnMouseMoved(GLFWwindow* handle, double x, double y);
        static void MouseButtonCallback(GLFWwindow* handle, int button, int action, int mods);
        static void ScrollCallback(GLFWwindow* handle, double x, double y);
    };
}


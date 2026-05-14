#pragma once
#include <core/Common.h>

namespace engine{
    class InputSystem {

    public:
        explicit InputSystem(const InputDesc& desc);
    private:

        static void OnKeyPressed(GLFWwindow* handle, int key, int scancode, int action, int mods);
        static void OnMouseMoved(GLFWwindow* handle, double x, double y);
    };
}


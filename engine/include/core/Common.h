//
// Created by umair on 5/3/2026.
//

#pragma once
#include <string>
#include <core/Core.h>
#include <glm/glm.hpp>

namespace engine {
    struct BaseDesc
    {
    };
    struct WindowUserData {
        Window* window;
        InputSystem* input;
    };
    struct WindowDesc {
        ui32 width;
        ui32 height;
        const char* title;
    };
    struct InputDesc {
       GLFWwindow* handle;
    };

    enum class EventType
    {
        None = 0,
        // Window
        WindowClose, WindowResize,
        // Keyboard  
        KeyPressed, KeyReleased,
        // Mouse
        MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled
    };

}


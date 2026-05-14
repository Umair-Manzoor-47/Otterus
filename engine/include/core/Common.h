//
// Created by umair on 5/3/2026.
//

#pragma once
#include <string>
#include <core/Core.h>

namespace engine {
    struct BaseDesc
    {
    };
    struct WindowDesc {
        ui32 width;
        ui32 height;
        const char* title;
    };
    struct InputDesc {
       GLFWwindow* handle;
    };
    struct ShaderDesc
    {
        std::string vertexPath;
        std::string fragmentPath;
    };
    struct MeshDesc
    {
        f32*   vertices;
        size_t size;
        ui32*  indices;
        i32 index_count;
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


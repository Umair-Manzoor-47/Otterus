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

    struct TransformDesc {
        glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 Scale    = glm::vec3(1.0f, 1.0f, 1.0f);
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


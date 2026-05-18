#include <input_system/InputSystem.h>
#include <event/Dispatcher.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <event/keyboard/KeyReleasedEvent.h>
#include <event/mouse/MouseMovedEvent.h>
#include <event/mouse/MouseButtonPressedEvent.h>
#include <event/mouse/MouseButtonReleasedEvent.h>
#include <event/mouse/MouseScrolledEvent.h>
#include <window/Window.h>


engine::InputSystem::InputSystem(const InputDesc& desc) {
    glfwSetKeyCallback(desc.handle, KeyCallback);
    glfwSetCursorPosCallback(desc.handle, OnMouseMoved);
    glfwSetMouseButtonCallback(desc.handle, MouseButtonCallback);
    glfwSetScrollCallback(desc.handle, ScrollCallback);
}

bool engine::InputSystem::IsKeyHeld(int keyCode) const
{
    return m_keyStates[keyCode];
}

void engine::InputSystem::KeyCallback(GLFWwindow *handle, int key, int scancode, int action, int mods) {
    WindowUserData* data = static_cast<WindowUserData*>(
        glfwGetWindowUserPointer(handle)
    );
    
    if (action == GLFW_PRESS) {
        data->input->m_keyStates[key] = true;
        KeyPressedEvent event{key};
        data->window->GetDispatcher().Dispatch(event);
    }
    else if (action == GLFW_RELEASE) {
        data->input->m_keyStates[key] = false;
        KeyReleasedEvent event{key};
        data->window->GetDispatcher().Dispatch(event);
    }
    else if (action == GLFW_REPEAT) {
        KeyPressedEvent event{key};
        data->window->GetDispatcher().Dispatch(event);
    }

}

void engine::InputSystem::OnMouseMoved(GLFWwindow *handle, double x, double y) {
    WindowUserData* data = static_cast<WindowUserData*>(
        glfwGetWindowUserPointer(handle)
    );
    MouseMovedEvent event{x, y};
    
    data->window->GetDispatcher().Dispatch(event);
}

void engine::InputSystem::MouseButtonCallback(GLFWwindow *handle, int button, int action, int mods)
{
    WindowUserData* data = static_cast<WindowUserData*>(
        glfwGetWindowUserPointer(handle)
    );
    if (action == GLFW_PRESS)
    {
        MouseButtonPressedEvent event{button};
        data->window->GetDispatcher().Dispatch(event);
    }
    else if (action == GLFW_RELEASE)
    {
        MouseButtonReleasedEvent event{button};
        data->window->GetDispatcher().Dispatch(event);
    }

}

void engine::InputSystem::ScrollCallback(GLFWwindow* handle, double x, double y)
{
    WindowUserData* data = static_cast<WindowUserData*>(
        glfwGetWindowUserPointer(handle)
    );
    MouseScrolledEvent event{x, y};
   data->window->GetDispatcher().Dispatch(event);
}
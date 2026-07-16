#include <Input/InputSystem.h>
#include <event/Dispatcher.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <event/keyboard/KeyReleasedEvent.h>
#include <event/mouse/MouseMovedEvent.h>
#include <event/mouse/MouseButtonPressedEvent.h>
#include <event/mouse/MouseButtonReleasedEvent.h>
#include <event/mouse/MouseScrolledEvent.h>
#include <Windowing/Window.h>

namespace otterus::windowing::input
{
    InputSystem::InputSystem(const InputDesc& desc) {
        glfwSetKeyCallback(desc.handle, KeyCallback);
        glfwSetCursorPosCallback(desc.handle, OnMouseMoved);
        glfwSetMouseButtonCallback(desc.handle, MouseButtonCallback);
        glfwSetScrollCallback(desc.handle, ScrollCallback);
    }

    bool InputSystem::IsKeyHeld(int keyCode) const
    {
        return m_keyStates[keyCode];
    }

    void InputSystem::KeyCallback(GLFWwindow *handle, int key, int scancode, int action, int mods) {
        WindowUserData* data = static_cast<WindowUserData*>(
            glfwGetWindowUserPointer(handle)
        );

        if (action == GLFW_PRESS) {
            data->input->m_keyStates[key] = true;
            event::KeyPressedEvent event{key};
            data->window->GetDispatcher().Dispatch(event);
        }
        else if (action == GLFW_RELEASE) {
            data->input->m_keyStates[key] = false;
            event::KeyReleasedEvent event{key};
            data->window->GetDispatcher().Dispatch(event);
        }
        else if (action == GLFW_REPEAT) {
            event::KeyPressedEvent event{key};
            data->window->GetDispatcher().Dispatch(event);
        }

    }

    void InputSystem::OnMouseMoved(GLFWwindow *handle, double x, double y) {
        WindowUserData* data = static_cast<WindowUserData*>(
            glfwGetWindowUserPointer(handle)
        );
        event::MouseMovedEvent event{x, y};

        data->window->GetDispatcher().Dispatch(event);
    }

    void InputSystem::MouseButtonCallback(GLFWwindow *handle, int button, int action, int mods)
    {
        WindowUserData* data = static_cast<WindowUserData*>(
            glfwGetWindowUserPointer(handle)
        );
        if (action == GLFW_PRESS)
        {
            event::MouseButtonPressedEvent event{button};
            data->window->GetDispatcher().Dispatch(event);
        }
        else if (action == GLFW_RELEASE)
        {
            event::MouseButtonReleasedEvent event{button};
            data->window->GetDispatcher().Dispatch(event);
        }

    }

    void InputSystem::ScrollCallback(GLFWwindow* handle, double x, double y)
    {
        WindowUserData* data = static_cast<WindowUserData*>(
            glfwGetWindowUserPointer(handle)
        );
        event::MouseScrolledEvent event{x, y};
        data->window->GetDispatcher().Dispatch(event);
    }
}
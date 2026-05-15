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

void engine::InputSystem::KeyCallback(GLFWwindow *handle, int key, int scancode, int action, int mods) {
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(handle));
    
    if (action == GLFW_PRESS) {
        KeyPressedEvent event{key};
        window->GetDispatcher().Dispatch(event);
    }
    else if (action == GLFW_RELEASE) {
        KeyReleasedEvent event{key};
        window->GetDispatcher().Dispatch(event);
    }
    else if (action == GLFW_REPEAT) {
        KeyPressedEvent event{key};
        window->GetDispatcher().Dispatch(event);
    }

}

void engine::InputSystem::OnMouseMoved(GLFWwindow *handle, double x, double y) {
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(handle));
    MouseMovedEvent event{x, y};
    
    window->GetDispatcher().Dispatch(event);
}

void engine::InputSystem::MouseButtonCallback(GLFWwindow *handle, int button, int action, int mods)
{
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(handle));
    if (action == GLFW_PRESS)
    {
        MouseButtonPressedEvent event{button};
        window->GetDispatcher().Dispatch(event);
    }
    else if (action == GLFW_RELEASE)
    {
        MouseButtonReleasedEvent event{button};
        window->GetDispatcher().Dispatch(event);
    }

}

void engine::InputSystem::ScrollCallback(GLFWwindow* handle, double x, double y)
{
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(handle));
    MouseScrolledEvent event{x, y};
    window->GetDispatcher().Dispatch(event);
}
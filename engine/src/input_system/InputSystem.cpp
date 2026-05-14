#include <input_system/InputSystem.h>
#include <event/Dispatcher.h>
#include <event/keyboard/KeyPressedEvent.h>
#include <window/Window.h>


engine::InputSystem::InputSystem(const InputDesc& desc) {
    glfwSetKeyCallback(desc.handle, OnKeyPressed);
    glfwSetCursorPosCallback(desc.handle, OnMouseMoved);
}

void engine::InputSystem::OnKeyPressed(GLFWwindow *handle, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS)
        return;
    const Window* window = static_cast<Window*>(glfwGetWindowUserPointer(handle));

    KeyPressedEvent event{key};
    window->GetDispatcher().Dispatch(event);

}

void engine::InputSystem::OnMouseMoved(GLFWwindow *handle, double x, double y) {
}

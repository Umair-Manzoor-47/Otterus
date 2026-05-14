#include <core/Logger.h>
#include <window/Window.h>
#include <event/window/WindowCloseEvent.h>

engine::Window::Window(const WindowDesc& desc, Dispatcher& dispatcher):m_height(desc.height), m_width(desc.width), m_title(desc.title), m_dispatcher(dispatcher) {}

void engine::Window::Init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_handle = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
    if (m_handle == NULL)
    {
        LogError("Failed to create GLFW window");
        glfwTerminate();
        return;
    }
    glfwSetWindowUserPointer(m_handle, this);

    glfwMakeContextCurrent(m_handle);
    glfwSetWindowCloseCallback(m_handle, OnWindowClose);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
         LogError("Failed to initialize GLAD");
        return;
    }

}
void engine::Window::Update() {

    glfwSwapBuffers(m_handle);
    glfwPollEvents();
}

void engine::Window::Destroy() {
    glfwDestroyWindow(m_handle);
    glfwTerminate();
}

void engine::Window::OnWindowClose(GLFWwindow* handle) {
    // retrieve Window instance
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(handle));
    
    // fire the event through dispatcher
    WindowCloseEvent event;
    window->m_dispatcher.Dispatch(event);
}
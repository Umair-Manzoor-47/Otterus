#include <logger/Logger.h>
#include <window/Window.h>
#include <event/window/WindowCloseEvent.h>
#include <event/window/WindowResizeEvent.h>

engine::Window::Window(const WindowDesc& desc, Dispatcher& dispatcher):m_height(desc.height), m_width(desc.width), m_title(desc.title), m_dispatcher(dispatcher) {}

void engine::Window::Init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_handle = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
    if (m_handle == NULL)
    {
        CORE_ERROR("Failed to create GLFW window");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_handle);
    glfwSetWindowCloseCallback(m_handle, OnWindowClose);
    glfwSetFramebufferSizeCallback(m_handle, OnWindowResize);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
         CORE_ERROR("Failed to initialize GLAD");
        return;
    }
    glEnable(GL_DEPTH_TEST);

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
    WindowUserData* data = static_cast<WindowUserData*>(
        glfwGetWindowUserPointer(handle)
    );
    // fire the event through dispatcher
    WindowCloseEvent event;
    data->window->m_dispatcher.Dispatch(event);
}

void engine::Window::OnWindowResize(GLFWwindow* handle, int width, int height) {
    // retrieve Window instance
    WindowUserData* data = static_cast<WindowUserData*>(
        glfwGetWindowUserPointer(handle)
    );   
    // fire the event through dispatcher
    WindowResizeEvent event{width, height};
    data->window->m_dispatcher.Dispatch(event);
}
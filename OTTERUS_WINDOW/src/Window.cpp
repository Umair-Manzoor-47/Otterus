#include <Windowing/Window.h>
#include <logger/Logger.h>
#include <event/window/WindowCloseEvent.h>
#include <event/window/WindowResizeEvent.h>

namespace otterus::windowing
{
    Window::Window(const WindowDesc& desc, event::Dispatcher& dispatcher):m_height(desc.height), m_width(desc.width), m_title(desc.title), m_dispatcher(dispatcher) {}

    void Window::Init() {
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
    void Window::Update() {

        glfwSwapBuffers(m_handle);
        glfwPollEvents();
    }

    void Window::Destroy() {
        glfwDestroyWindow(m_handle);
        glfwTerminate();
    }

    void Window::OnWindowClose(GLFWwindow* handle) {
        // retrieve Window instance
        WindowUserData* data = static_cast<WindowUserData*>(
            glfwGetWindowUserPointer(handle)
        );
        // fire the event through dispatcher
        event::WindowCloseEvent event;
        data->window->m_dispatcher.Dispatch(event);
    }

    void Window::OnWindowResize(GLFWwindow* handle, int width, int height) {
        // retrieve Window instance
        WindowUserData* data = static_cast<WindowUserData*>(
            glfwGetWindowUserPointer(handle)
        );
        // fire the event through dispatcher
        event::WindowResizeEvent event{width, height};
        data->window->m_dispatcher.Dispatch(event);
    }
}
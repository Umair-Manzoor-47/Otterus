#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/Common.h>
#include <event/Dispatcher.h>
#include <core/Core.h>
#include <functional>
namespace engine{
class Window {
public:
    Window(const WindowDesc& desc, Dispatcher& dispatcher);
    void Init();
    void Update();
    void Destroy();
    GLFWwindow* GetWindowHandle() const { return m_handle; }
    Dispatcher& GetDispatcher() const { return m_dispatcher; }

private:
    GLFWwindow* m_handle = nullptr;
    Dispatcher& m_dispatcher;
    ui32 m_width;
    ui32 m_height;
    const char* m_title;
    
    static void OnWindowClose(GLFWwindow* handle);
};

}

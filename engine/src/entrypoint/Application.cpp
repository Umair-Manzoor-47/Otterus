//
// Created by umair on 5/8/2026.
//

#include <entrypoint/Application.h>
#include <event/window/WindowCloseEvent.h>
#include <window/Window.h>


void engine::Application::Run() {
    Init();
    OnStart();
    while (m_Running) {
        OnUpdate(calculateDeltaTime());
        OnRender();
        m_window->Update();
    }

    OnShutdown();
    m_window->Destroy();

}


void engine::Application::CreateGraphicsEngine() {
    m_graphics_engine = std::make_unique<GraphicsEngine>();
}


void engine::Application::Init()
{
    m_window = std::make_unique<Window>(
        GetWindowDesc(),
        m_dispatcher);
    m_window->Init();
    m_inputSystem = std::make_unique<InputSystem>(
    InputDesc{ m_window->GetWindowHandle() }
);
    m_camera = std::make_shared<Camera>();
    m_dispatcher.Subscribe<WindowCloseEvent>([this](WindowCloseEvent& e) {
        m_Running = false;
        e.Handled = true;
    });
    CreateGraphicsEngine();
    m_windowUserData = { m_window.get(), m_inputSystem.get() };
    glfwSetWindowUserPointer(m_window->GetWindowHandle(), &m_windowUserData);
}

float engine::Application::calculateDeltaTime()
{
    float currentTime = glfwGetTime();
    float deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;
    return deltaTime;
}
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
        OnUpdate();
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
}
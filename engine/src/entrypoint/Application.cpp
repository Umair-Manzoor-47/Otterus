//
// Created by umair on 5/8/2026.
//

#include <entrypoint/Application.h>
#include <core/Logger.h>
#include <event/window/WindowCloseEvent.h>
#include <window/Window.h>


void engine::Application::Run() {
    Init();
    OnStart();
    while (m_Running) {
        OnUpdate();
        m_graphics_engine->Draw();
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
        WindowDesc{
            800,
            600,
            "Otterus"
        },
        m_dispatcher);
    m_window->Init();
    m_dispatcher.Subscribe<WindowCloseEvent>([this](WindowCloseEvent& e) {
        m_Running = false;
        e.Handled = true;
    });
    CreateGraphicsEngine();
}
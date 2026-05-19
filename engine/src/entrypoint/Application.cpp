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
        m_context->GetWindow().Update();
    }

    OnShutdown();
    m_context->GetWindow().Destroy();

}



void engine::Application::Init()
{
    m_context = std::make_unique<EngineContext>(GetWindowDesc());
    m_context->GetDispatcher().Subscribe<WindowCloseEvent>([this](WindowCloseEvent& e) {
        m_Running = false;
        e.Handled = true;
    });
    
}

float engine::Application::calculateDeltaTime()
{
    float currentTime = glfwGetTime();
    float deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;
    return deltaTime;
}
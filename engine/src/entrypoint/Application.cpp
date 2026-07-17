#include <entrypoint/Application.h>
#include <event/window/WindowCloseEvent.h>
#include <Windowing/Window.h>


void engine::Application::Run() {
    Init();
    OnStart();
    while (m_Running) {
        OnFrameBegin();
        OnUpdate(calculateDeltaTime());
        OnRender();
        OnFrameEnd();
        m_context->GetWindow().Update();
    }

    OnShutdown();
    m_context->GetWindow().Destroy();

}



void engine::Application::Init()
{
    m_context = std::make_unique<EngineContext>(GetWindowDesc());
    m_context->GetDispatcher().Subscribe<otterus::windowing::event::WindowCloseEvent>([this](otterus::windowing::event::WindowCloseEvent& e) {
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
#include <entrypoint/Application.h>
#include <event/window/WindowCloseEvent.h>
#include <Windowing/Window.h>
#include <logger/Logger.h>
#include <Rendering/Core/GraphicsEngine.h>
#include <event/Dispatcher.h>
#include <Windowing/Window.h>
#include <Input/InputSystem.h>

void engine::Application::Run() {
    Init();
    OnStart();
    while (m_Running) {
        OnFrameBegin();
        OnUpdate(calculateDeltaTime());
        OnRender();
        OnFrameEnd();

        auto& window = m_registry->GetContext<std::shared_ptr<otterus::windowing::Window>>();
        if (!window) {
            OT_ERROR("Failed to get window from Registry.");
            return;
        }
        window->Update();
    }

    OnShutdown();
    auto& window = m_registry->GetContext<std::shared_ptr<otterus::windowing::Window>>();
    window->Destroy();

}



void engine::Application::Init()
{
    otterus_logger::Logger::Init();
    m_registry = std::make_unique<otterus_core::ECS::Registry>();
    if (!m_registry) {
        OT_ERROR("Failed to create the EnTT registry");
        return;
    }
    auto m_dispatcher = std::make_shared<otterus::windowing::event::Dispatcher>();
    if (!m_registry->AddToContext<std::shared_ptr<otterus::windowing::event::Dispatcher>>(m_dispatcher)) {
        OT_ERROR("Failed to add Dispatcher to registry context.");
        return;
    }

    auto m_window = std::make_shared<otterus::windowing::Window>(
    otterus::windowing::WindowDesc{1920, 1080, "Otterus"},
    *m_registry
    );
    m_window->Init();
    if (!m_registry->AddToContext<std::shared_ptr<otterus::windowing::Window>>(m_window)) {
        OT_ERROR("Failed to add window to registry context.");
        return;
    }

    auto m_inputSystem = std::make_shared<otterus::windowing::input::InputSystem>(
        otterus::windowing::input::InputDesc{ m_window->GetWindowHandle() }
        );
    if (!m_registry->AddToContext<std::shared_ptr<otterus::windowing::input::InputSystem>>(m_inputSystem)) {
        OT_ERROR("Failed to add input system to registry context.");
        return;
    }

    auto m_graphicsEngine = std::make_shared<otterus_rendering::GraphicsEngine>();
    if (!m_registry->AddToContext<std::shared_ptr<otterus_rendering::GraphicsEngine>>(m_graphicsEngine)) {
        OT_ERROR("Failed to add input system to registry context.");
        return;
    }

    m_windowUserData = { m_window.get(), m_inputSystem.get() };
    glfwSetWindowUserPointer(m_window->GetWindowHandle(), &m_windowUserData);
    m_dispatcher->Subscribe<otterus::windowing::event::WindowCloseEvent>([this](otterus::windowing::event::WindowCloseEvent& e) {
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
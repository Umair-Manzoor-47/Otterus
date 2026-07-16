#include <engine_context/EngineContext.h>
#include <logger/Logger.h>

engine::EngineContext::EngineContext(const otterus::windowing::WindowDesc& window_desc){

    otterus_logger::Logger::Init();
    m_window = std::make_unique<otterus::windowing::Window>(
        window_desc, 
        m_dispatcher
        );
    m_window->Init();
    
    m_inputSystem = std::make_unique<otterus::windowing::input::InputSystem>(
        otterus::windowing::input::InputDesc{ m_window->GetWindowHandle() }
        );
    m_graphicsEngine = std::make_unique<otterus_rendering::GraphicsEngine>();
    
    m_windowUserData = { m_window.get(), m_inputSystem.get() };
    glfwSetWindowUserPointer(m_window->GetWindowHandle(), &m_windowUserData);
}

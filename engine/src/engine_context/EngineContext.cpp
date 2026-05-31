#include <engine_context/EngineContext.h>
#include <core/Logger.h>

engine::EngineContext::EngineContext(const WindowDesc& window_desc){

    engine::Logger::Init();
    m_window = std::make_unique<Window>(
        window_desc, 
        m_dispatcher
        );
    m_window->Init();
    
    m_inputSystem = std::make_unique<InputSystem>( 
        InputDesc{ m_window->GetWindowHandle() }
        );
    m_graphicsEngine = std::make_unique<GraphicsEngine>();
    
    m_windowUserData = { m_window.get(), m_inputSystem.get() };
    glfwSetWindowUserPointer(m_window->GetWindowHandle(), &m_windowUserData);
}

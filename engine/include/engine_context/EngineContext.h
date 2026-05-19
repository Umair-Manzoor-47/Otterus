#pragma once
#include <core/Core.h>
#include <graphics/GraphicsEngine.h>
#include <event/Dispatcher.h>
#include <window/Window.h>
#include <input_system/InputSystem.h>

namespace engine
{
    class EngineContext
    {
    public:
        explicit EngineContext(const WindowDesc& window_desc);
        
        Dispatcher& GetDispatcher() { return m_dispatcher; }
        Window& GetWindow() { return *m_window; }
        InputSystem& GetInputSystem(){ return *m_inputSystem; }
        GraphicsEngine& GetGraphicsEngine() { return *m_graphicsEngine; }
        
    private:
        Dispatcher m_dispatcher{};
        std::unique_ptr<Window> m_window;
        std::unique_ptr<InputSystem> m_inputSystem;
        std::unique_ptr<GraphicsEngine> m_graphicsEngine;
        WindowUserData m_windowUserData;
    
    };
    
}
#pragma once
#include <types/Type.h>
#include <Rendering/Core/GraphicsEngine.h>
#include <event/Dispatcher.h>
#include <Windowing/Window.h>
#include <Input/InputSystem.h>

namespace engine
{
    class EngineContext
    {
    public:
        explicit EngineContext(const otterus::windowing::WindowDesc& window_desc);
        
        otterus::windowing::event::Dispatcher& GetDispatcher() { return m_dispatcher; }
        otterus::windowing::Window& GetWindow() { return *m_window; }
        otterus::windowing::input::InputSystem& GetInputSystem(){ return *m_inputSystem; }
        otterus_rendering::GraphicsEngine& GetGraphicsEngine() { return *m_graphicsEngine; }
        
    private:
        otterus::windowing::event::Dispatcher m_dispatcher{};
        std::unique_ptr<otterus::windowing::Window> m_window;
        std::unique_ptr<otterus::windowing::input::InputSystem> m_inputSystem;
        std::unique_ptr<otterus_rendering::GraphicsEngine> m_graphicsEngine;
        otterus::windowing::WindowUserData m_windowUserData;
    
    };
    
}
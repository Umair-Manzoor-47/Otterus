#pragma once
#include <Rendering/Core/Camera.h>
#include <types/Type.h>
#include <Rendering/Core/GraphicsEngine.h>
#include <Windowing/Window.h>
#include <Input/InputSystem.h>
#include <engine_context/EngineContext.h>

namespace engine {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate(float deltaTime) = 0;
        virtual void OnShutdown() = 0;
        virtual void OnRender() = 0;
        virtual void OnFrameBegin() = 0;
        virtual void OnFrameEnd() = 0;
        virtual otterus::windowing::WindowDesc GetWindowDesc() {
            return otterus::windowing::WindowDesc{1920, 1080, "Otterus"};
        }


        virtual void Init();
        void Run();

    protected:
        bool m_Running = true;
        EngineContext& GetContext() { return *m_context; }

    private:
        std::unique_ptr<EngineContext> m_context;
        float m_lastTime = 0.f;
        
        float calculateDeltaTime();
    };


}

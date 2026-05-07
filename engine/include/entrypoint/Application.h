//
// Created by umair on 5/8/2026.
//
#pragma once

namespace engine {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutdown() = 0;

        void Run();

    protected:
        bool m_Running = true;
    };


}

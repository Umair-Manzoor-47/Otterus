//
// Created by umair on 5/8/2026.
//

#include <entrypoint/Application.h>

void engine::Application::Run() {

    OnStart();

    while (m_Running) {
        OnUpdate();
    }

    OnShutdown();

}

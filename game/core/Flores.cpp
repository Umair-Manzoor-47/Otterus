//
// Created by umair on 5/8/2026.
//

#include "Flores.h"

#include <core/Logger.h>

void Flores::OnStart() {
    LogInfo("Flores started.");
}

void Flores::OnUpdate() {
    m_FrameCount++;
    LogInfo("Frame update.");

    if (m_FrameCount >= 5) {
        m_Running = false;
    }
}

void Flores::OnShutdown() {
    LogInfo("Flores shutdown.");
}

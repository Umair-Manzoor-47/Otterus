//
// Created by umair on 5/8/2026.
//

#include "Flores.h"
#include <core/Logger.h>
void Flores::OnStart() {
    LogInfo("Flores started.");
}

void Flores::OnUpdate() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Flores::OnShutdown() {
    LogInfo("Flores shutdown.");
}

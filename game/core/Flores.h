//
// Created by umair on 5/8/2026.
//
#pragma once

#include <entrypoint/Application.h>
#include <core/Core.h>

class Flores : public engine::Application {
public:
    void OnStart() override;
    void OnUpdate() override;
    void OnShutdown() override;
private:
    engine::i32 m_FrameCount;
};
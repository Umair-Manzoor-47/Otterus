//
// Created by umair on 5/8/2026.
//
#pragma once

#include <entrypoint/Application.h>
#include <core/Core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Flores : public engine::Application {
public:
    void OnStart() override;
    void OnUpdate() override;
    void OnShutdown() override;
};

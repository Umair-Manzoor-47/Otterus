//
// Created by umair on 5/8/2026.
//

#include <entrypoint/Application.h>
#include <core/Logger.h>



void engine::Application::Run() {
    CreateGraphicsEngine();
    InitWindow();
    OnStart();
    while (m_Running) {
        OnUpdate();
        UpdateWindow();
    }

    OnShutdown();
    ShutdownWindow();

}

void engine::Application::InitWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(800, 600, "Otterus", NULL, NULL);
    if (window == NULL)
    {
        LogError("Failed to create GLFW window");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
         LogError("Failed to initialize GLAD");
        return;
    }

}

void engine::Application::UpdateWindow() {
    if (glfwWindowShouldClose(window)) {
        m_Running = false;
        return;
    }
    m_graphics_engine->Draw();
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void engine::Application::ShutdownWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void engine::Application::CreateGraphicsEngine() {
    m_graphics_engine = std::make_unique<GraphicsEngine>();
}



cmake_minimum_required(VERSION 3.26)
project(OtterusEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC)


target_sources(OtterusEngine PRIVATE
        src/camera/Camera.cpp
        src/engine_context/EngineContext.cpp
        src/entrypoint/Application.cpp
        src/game_object/GameObject.cpp
        src/resource_manager/ResourceManager.cpp
        src/graphics/MeshLoader.cpp
        src/graphics/Shader.cpp
        src/graphics/Mesh.cpp
        src/input_system/InputSystem.cpp
        src/graphics/Texture.cpp
        src/graphics/Transform.cpp
        src/event/Dispatcher.cpp
        src/core/Logger.cpp
        src/window/Window.cpp
        src/scene/Scene.cpp
        src/graphics/GraphicsEngine.cpp
        src/graphics/TinyObjLoader.cpp
        src/loaders/TextureLoader.cpp
        src/loaders/stb_img.cpp
)

target_include_directories(OtterusEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/vendor/glad/include
        ${CMAKE_SOURCE_DIR}/vendor/tiny_obj_loader
        ${CMAKE_SOURCE_DIR}/vendor/stb

)

target_link_libraries(OtterusEngine PUBLIC glfw spdlog::spdlog glm::glm)
cmake_minimum_required(VERSION 3.26)
project(OtterusEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC)


target_sources(OtterusEngine PRIVATE
        src/engine_context/EngineContext.cpp
        src/entrypoint/Application.cpp
        src/game_object/GameObject.cpp
        ../OTTERUS_CORE/src/ResourceManager.cpp
        src/input_system/InputSystem.cpp
        src/event/Dispatcher.cpp
        src/window/Window.cpp
        src/scene/Scene.cpp
)

target_include_directories(OtterusEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src

)
target_link_libraries(OtterusEngine
        PUBLIC
        glfw
        glm::glm
        OTTERUS_LOGGER
        OTTERUS_RENDERING
        OTTERUS_CORE
)
cmake_minimum_required(VERSION 3.26)
project(OtterusEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC)


target_sources(OtterusEngine PRIVATE
        src/entrypoint/Application.cpp
        src/game_object/GameObject.cpp
        src/scene/Scene.cpp
)

target_include_directories(OtterusEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/vendor

)
target_link_libraries(OtterusEngine
        PUBLIC
        glfw
        glm::glm
        OTTERUS_LOGGER
        OTTERUS_RENDERING
        OTTERUS_CORE
        OTTERUS_WINDOW
)
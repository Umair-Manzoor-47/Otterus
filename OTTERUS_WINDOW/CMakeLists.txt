cmake_minimum_required(VERSION 3.26)
project(OTTERUS_WINDOW)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC
        src/Window.cpp
        src/InputSystem.cpp
        src/Dispatcher.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        glad
        glfw
        OTTERUS_LOGGER
)
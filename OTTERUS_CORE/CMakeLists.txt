cmake_minimum_required(VERSION 3.26)
project(OTTERUS_CORE)

add_library(${PROJECT_NAME} STATIC
        src/ResourceManager.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Core
)

target_link_libraries(OTTERUS_CORE
        PUBLIC
        glad
        glfw
        glm::glm
        OTTERUS_LOGGER
        OTTERUS_RENDERING
)
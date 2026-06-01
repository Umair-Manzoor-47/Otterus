cmake_minimum_required(VERSION 3.26)
project(Otterus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/utf-8)
endif() 

# Third party
add_subdirectory(vendor/glfw)

# Collect all source files
file(GLOB_RECURSE SOURCES
        "engine/src/**.cpp"
        "game/**.cpp"
        "editor/**.cpp"
)

add_executable(Otterus ${SOURCES})
target_sources(Otterus PRIVATE vendor/glad/src/glad.c)
target_sources(Otterus PRIVATE
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_draw.cpp
        vendor/imgui/imgui_tables.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/imgui/backends/imgui_impl_glfw.cpp
        vendor/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(Otterus PRIVATE
        ${CMAKE_SOURCE_DIR}/engine/include
        ${CMAKE_SOURCE_DIR}/engine/src
        ${CMAKE_SOURCE_DIR}/editor/include
        ${CMAKE_SOURCE_DIR}/editor/src
        ${CMAKE_SOURCE_DIR}/vendor
        ${CMAKE_SOURCE_DIR}/vendor/spdlog/include
        ${CMAKE_SOURCE_DIR}/vendor/glad/include
        ${CMAKE_SOURCE_DIR}/vendor/glad/src
        ${CMAKE_SOURCE_DIR}/vendor/glm
        ${CMAKE_SOURCE_DIR}/vendor/tiny_obj_loader

)
target_include_directories(Otterus PRIVATE
        ${CMAKE_SOURCE_DIR}/vendor/imgui
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends
)
target_link_libraries(Otterus PRIVATE glfw)
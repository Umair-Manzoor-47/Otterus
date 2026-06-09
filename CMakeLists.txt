cmake_minimum_required(VERSION 3.26)
project(Otterus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/utf-8)
endif()

# Speed
#set(CMAKE_UNITY_BUILD ON)
#set(CMAKE_UNITY_BUILD_BATCH_SIZE 16)

# Third party
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/spdlog)
add_subdirectory(engine)

# ImGui — one tidy static lib, nothing leaks out of here
add_library(imgui STATIC
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_draw.cpp
        vendor/imgui/imgui_tables.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/imgui/imgui_demo.cpp
        vendor/imgui/backends/imgui_impl_glfw.cpp
        vendor/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC
        vendor/imgui
        vendor/imgui/backends
)
target_link_libraries(imgui PUBLIC glfw)

set_target_properties(imgui PROPERTIES UNITY_BUILD OFF)

# Game + Editor
file(GLOB_RECURSE SOURCES
        "game/**.cpp"
        "editor/**.cpp"
)

add_executable(Otterus ${SOURCES})

target_sources(Otterus PRIVATE vendor/glad/src/glad.c)

target_include_directories(Otterus PRIVATE
        ${CMAKE_SOURCE_DIR}/editor/include
        ${CMAKE_SOURCE_DIR}/editor/src
        ${CMAKE_SOURCE_DIR}/vendor
)

target_link_libraries(Otterus PRIVATE
        glfw
        OtterusEngine
        imgui
)

# Most included stable headers.
target_precompile_headers(Otterus PRIVATE
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_SOURCE_DIR}/pch.h>"
)
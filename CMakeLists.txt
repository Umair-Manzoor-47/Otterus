cmake_minimum_required(VERSION 3.26)
project(Otterus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Third party
add_subdirectory(vendor/glfw)

# Collect all source files
file(GLOB_RECURSE SOURCES
        "engine/src/**.cpp"
        "game/**.cpp"
)

add_executable(Otterus ${SOURCES})
target_sources(Otterus PRIVATE vendor/glad/src/glad.c)
target_include_directories(Otterus PRIVATE
        ${CMAKE_SOURCE_DIR}/engine/include
        ${CMAKE_SOURCE_DIR}/engine/src
        ${CMAKE_SOURCE_DIR}/vendor
        ${CMAKE_SOURCE_DIR}/vendor/glad/include
        ${CMAKE_SOURCE_DIR}/vendor/glad/src
        ${CMAKE_SOURCE_DIR}/vendor/glm

)

target_link_libraries(Otterus PRIVATE glfw)
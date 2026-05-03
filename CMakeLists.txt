cmake_minimum_required(VERSION 3.26)
project(Otterus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB_RECURSE SOURCES
        "engine/src/*.cpp"
        "engine/entrypoint/*.cpp"
)

add_executable(Otterus ${SOURCES})

target_include_directories(Otterus PRIVATE
        ${CMAKE_SOURCE_DIR}/engine/include
        ${CMAKE_SOURCE_DIR}/vendor
)

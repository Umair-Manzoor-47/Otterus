cmake_minimum_required(VERSION 3.26)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(MyEngine ${SOURCES})

target_include_directories(MyEngine PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/vendor
)
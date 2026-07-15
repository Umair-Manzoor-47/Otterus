cmake_minimum_required(VERSION 3.26)
project(OTTERUS_LOGGER)

add_library(${PROJECT_NAME} STATIC
        logger/Logger.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_link_libraries(OTTERUS_LOGGER
        PUBLIC
        spdlog::spdlog
)
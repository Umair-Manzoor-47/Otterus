//
// Created by umair on 5/6/2026.
//
#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <memory>
#include <spdlog/spdlog.h>

namespace engine {

    class Logger {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return m_coreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return m_clientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> m_coreLogger;
        static std::shared_ptr<spdlog::logger> m_clientLogger;
    };
}

// Core log macros
#define CORE_TRACE(...)   SPDLOG_LOGGER_TRACE(::engine::Logger::GetCoreLogger(), __VA_ARGS__)
#define CORE_INFO(...)    SPDLOG_LOGGER_INFO(::engine::Logger::GetCoreLogger(), __VA_ARGS__)
#define CORE_WARN(...)    SPDLOG_LOGGER_WARN(::engine::Logger::GetCoreLogger(), __VA_ARGS__)
#define CORE_ERROR(...)   SPDLOG_LOGGER_ERROR(::engine::Logger::GetCoreLogger(), __VA_ARGS__)
#define CORE_FATAL(...)   SPDLOG_LOGGER_CRITICAL(::engine::Logger::GetCoreLogger(), __VA_ARGS__)

// Client log macros
#define OT_TRACE(...)     SPDLOG_LOGGER_TRACE(::engine::Logger::GetClientLogger(), __VA_ARGS__)
#define OT_INFO(...)      SPDLOG_LOGGER_INFO(::engine::Logger::GetClientLogger(), __VA_ARGS__)
#define OT_WARN(...)      SPDLOG_LOGGER_WARN(::engine::Logger::GetClientLogger(), __VA_ARGS__)
#define OT_ERROR(...)     SPDLOG_LOGGER_ERROR(::engine::Logger::GetClientLogger(), __VA_ARGS__)
#define OT_FATAL(...)     SPDLOG_LOGGER_CRITICAL(::engine::Logger::GetClientLogger(), __VA_ARGS__)
//
// Created by umair on 5/6/2026.
//
#pragma once
#include <iostream>

namespace engine {

    enum class LogLevel {
        Info,
        Warning,
        Error,
    };

    class Logger {
    public:
        Logger() = default;

        static void Log(LogLevel level, const char* message);
        static void LogContext(LogLevel level, const char* file, int line, const char* message);

    private:
        static const char* GetPrefix(LogLevel level);
    };
}

#define LogError(message) engine::Logger::LogContext(engine::LogLevel::Error, __FILE__, __LINE__, message)

#define LogWarning(message) engine::Logger::LogContext(engine::LogLevel::Warning, __FILE__, __LINE__, message)

#define LogInfo(message) engine::Logger::LogContext(engine::LogLevel::Info, __FILE__, __LINE__, message)
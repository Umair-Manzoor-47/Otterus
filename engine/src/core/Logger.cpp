//
// Created by umair on 5/6/2026.
//

#include <cstring>
#include <core/Logger.h>

void engine::Logger::Log(LogLevel level, const char* message) {
    std::cout << GetPrefix(level) << message;
}

void engine::Logger::LogContext(LogLevel level, const char* file, int line, const char* message) {
    const char* slash = strrchr(file, '/');
    const char* backslash = strrchr(file, '\\');
    const char* last = slash > backslash ? slash : backslash;
    const char* filename = last ? last + 1 : file;

    std::cout << GetPrefix(level) << message << " (" << filename << ":" << line << ")" << std::endl;
}

const char * engine::Logger::GetPrefix(LogLevel level) {
    switch (level) {
        case LogLevel::Info:    return "\033[40;35m[INFO]\033[0m ";
        case LogLevel::Warning: return "\033[40;33m[WARN]\033[0m ";
        case LogLevel::Error:   return "\033[40;31m[ERROR]\033[0m ";
        default:                return "[TRACE] ";
    }
}

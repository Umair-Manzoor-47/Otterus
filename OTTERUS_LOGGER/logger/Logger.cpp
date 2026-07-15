//
// Created by umair on 5/6/2026.
//

#include <logger/Logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> otterus_logger::Logger::m_coreLogger;
std::shared_ptr<spdlog::logger> otterus_logger::Logger::m_clientLogger;

void otterus_logger::Logger::Init() {
    if (m_coreLogger) return;
    spdlog::set_pattern("%^[%T] [%L] %n (%s:%#): %v%$");
    m_coreLogger = spdlog::stdout_color_mt("Otterus", spdlog::color_mode::automatic);
    m_coreLogger->set_level(spdlog::level::trace);

    m_clientLogger = spdlog::stdout_color_mt("APP", spdlog::color_mode::automatic);
    m_clientLogger->set_level(spdlog::level::trace);
}

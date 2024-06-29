#pragma once

#include <pthread.h>
#include <chrono>
#include <iostream>
#include <memory>
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#define LOG_TRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define LOG_DBG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define LOG_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define LOG_WARN(...) SPDLOG_WARN(__VA_ARGS__)
#define LOG_ERR(...) SPDLOG_ERROR(__VA_ARGS__)
#define LOG_CRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)

/**
 * @brief initial spdlog
 * 
 * @param console_level level for console output
 * @param file_level level for daily file output
 */
void log_init(spdlog::level::level_enum console_level,
              spdlog::level::level_enum file_level);
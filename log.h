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

#define LOG_TRACE(x) SPDLOG_TRACE(x)
#define LOG_DBG(x) SPDLOG_DEBUG(x)
#define LOG_INFO(x) SPDLOG_INFO(x)
#define LOG_WARN(x) SPDLOG_WARN(x)
#define LOG_ERR(x) SPDLOG_ERROR(x)
#define LOG_CRITICAL(x) SPDLOG_CRITICAL(x)

/**
 * @brief initial spdlog
 * 
 * @param console_level level for console output
 * @param file_level level for daily file output
 */
void log_init(spdlog::level::level_enum console_level,
              spdlog::level::level_enum file_level);
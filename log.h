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

void spdlog_init(spdlog::level::level_enum console_level,
                 spdlog::level::level_enum file_level) {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(console_level);
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S %z] [%^%L%$] %@ %v");

    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(
        "logs/daily.txt", 2, 30);
    file_sink->set_level(file_level);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S %z] [%^%L%$] %@ %v");

    spdlog::sinks_init_list sink_list = {file_sink, console_sink};

    spdlog::logger logger("multi_sink", sink_list.begin(), sink_list.end());
    logger.set_level(spdlog::level::debug);

    // or you can even set multi_sink logger as default logger
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(
        "multi_sink", spdlog::sinks_init_list({console_sink, file_sink})));

    spdlog::flush_on(spdlog::level::warn);
    spdlog::flush_every(std::chrono::seconds(3));
}
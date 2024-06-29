#include "log.h"

int main() {
    spdlog_init(spdlog::level::warn, spdlog::level::trace);

    SPDLOG_WARN("this should appear in both console and file");
    SPDLOG_INFO(
        "this message should not appear in the console, only in the file");
}
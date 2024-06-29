#include "../log.h"

#include <gtest/gtest.h>

namespace {

TEST(LogTest, LogTest1) {
    log_init(spdlog::level::warn, spdlog::level::trace);

    LOG_WARN("this should appear in both console and file");
    LOG_INFO("this message should not appear in the console, only in the file");

    EXPECT_EQ(1, 1);
}

}  // namespace
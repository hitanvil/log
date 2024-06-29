cmake_minimum_required(VERSION 3.14)
project(log_test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=format -O3  -mavx -mavx2")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=format -O0 -g -mavx -mavx2")

# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

include(FetchContent)
FetchContent_Declare(
    googletest

    # URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    URL file:///home/ath/Downloads/googletest-1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(../)

add_executable(
    log_test
    log_test.cpp
    ../log.cpp
)
target_link_libraries(
    log_test
    GTest::gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(log_test)
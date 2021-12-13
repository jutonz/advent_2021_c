cmake_minimum_required(VERSION 3.22)

project(Advent2021 LANGUAGES C CXX)

# googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

# Day 1
add_executable(day1-1 src/day1/part1/main.c)
add_library(day1-2_helpers src/day1/part2/helpers.c src/day1/part2/helpers.h)
add_executable(day1-2 src/day1/part2/main.c)
target_link_libraries(day1-2 day1-2_helpers)

# Testing
enable_testing()

add_executable(day1-2_test src/day1/part2/helpers_test.cc)
target_link_libraries(day1-2_test day1-2_helpers)
target_link_libraries(day1-2_test gtest_main)

include(GoogleTest)
gtest_discover_tests(day1-2_test)

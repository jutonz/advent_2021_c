cmake_minimum_required(VERSION 3.22)

project(Advent2021 LANGUAGES C CXX)

# googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

# General utilities
add_library(file src/file.c src/file.h)

# Day 1
add_executable(day1-1 src/day1/part1/main.c)
add_library(day1-2_helpers src/day1/part2/helpers.c src/day1/part2/helpers.h)
add_executable(day1-2 src/day1/part2/main.c)
target_link_libraries(day1-2 day1-2_helpers)

# Day 2
add_executable(day2-1 src/day2/part1.c)
add_library(day2_point src/day2/point.c src/day2/point.h)
target_link_libraries(day2-1 file day2_point)
add_executable(day2-2 src/day2/part2.c)
target_link_libraries(day2-2 file day2_point)

# Testing
enable_testing()

add_executable(day1-2_test src/day1/part2/helpers_test.cc)
target_link_libraries(day1-2_test gtest_main day1-2_helpers)

add_executable(day2-1_test src/day2/point_test.cc)
target_link_libraries(day2-1_test gtest_main day2_point)

include(GoogleTest)
gtest_discover_tests(day1-2_test)
gtest_discover_tests(day2-1_test)

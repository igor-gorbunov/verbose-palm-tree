cmake_minimum_required(VERSION 3.13)

project(verbose-palm-tree)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(verbose-palm-tree main.cpp test_radix_sort.cpp radix_sort.hpp radix_sort.cpp)
target_link_libraries(verbose-palm-tree GTest::GTest GTest::Main)


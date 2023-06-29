cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/")

find_package(Zephyr REQUIRED HINTS ../zephyr)
project(k_wakeup_test)

target_sources(app PRIVATE src/main.c)

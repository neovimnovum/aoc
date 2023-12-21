cmake_minimum_required(VERSION 3.20)
project(aoc, LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(day1 ${PROJECT_SOURCE_DIR}/src/day1.cpp)
include_directories(AFTER ${PROJECT_SOURCE_DIR}/inc)
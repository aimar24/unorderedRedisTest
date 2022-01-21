cmake_minimum_required(VERSION 3.5)

project(unorderedRedisTestBenchmark LANGUAGES CXX)

include_directories( )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unorderedRedisTestBenchmark main.cpp)

target_link_libraries(unorderedRedisTestBenchmark hiredis benchmark pthread)

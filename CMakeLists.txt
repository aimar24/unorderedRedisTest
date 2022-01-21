cmake_minimum_required(VERSION 3.5)

project(unorderedRedisTest LANGUAGES CXX)

include_directories( )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unorderedRedisTest main.cpp)

add_subdirectory(./benchmark)

target_link_libraries(unorderedRedisTest hiredis)

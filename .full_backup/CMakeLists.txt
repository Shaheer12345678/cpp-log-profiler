cmake_minimum_required(VERSION 3.16)
project(logprof CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(ENABLE_TESTS "Enable unit tests" ON)

add_library(logutil
    src/tokenize.cpp
    src/stats.cpp
    src/timer.cpp
)
target_include_directories(logutil PUBLIC include)

add_executable(logprof src/main.cpp)
target_link_libraries(logprof PRIVATE logutil)

if(ENABLE_TESTS)
  include(FetchContent)
  FetchContent_Declare(googletest

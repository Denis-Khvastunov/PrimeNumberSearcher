cmake_minimum_required(VERSION 3.12)
project(ListatTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(ListatTest main.cpp XMLparser.cpp XMLparser.h PrimeSearcher.cpp PrimeSearcher.h ParserTEST.h SearcherTEST.h)

target_link_libraries(ListatTest gtest gtest_main)


cmake_minimum_required(VERSION 2.8)
project(mutex-test)
add_definitions(-std=c++11)
set(sources main.cpp)
add_executable(mutex-test ${sources})


cmake_minimum_required(VERSION 4.2)
project(overloading_hw)

set(CMAKE_CXX_STANDARD 20)

add_executable(overloading_hw main.cpp
        Time.cpp
        Time.h
        Schedule.cpp
        Schedule.h
        Bus.cpp
        Bus.h)

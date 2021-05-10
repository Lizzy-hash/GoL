cmake_minimum_required(VERSION 3.19)
project(GameOfLife_Clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GameOfLife_Clion
        api_window.cpp
        api_window.h
        board.cpp
        board.h
        engine.cpp
        engine.h
        main.cpp
        txt.cpp
        txt.h)

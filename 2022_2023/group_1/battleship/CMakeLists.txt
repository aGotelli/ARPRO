cmake_minimum_required(VERSION 3.5)

project(battleship LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_BUILD_TYPE Debug)

add_executable(battleship main.cpp
                          include/board.h
                          include/player.h
    )

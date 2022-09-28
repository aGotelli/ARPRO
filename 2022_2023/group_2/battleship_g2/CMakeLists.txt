cmake_minimum_required(VERSION 3.5)

project(battleship_g2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(battleship_g2 main.cpp
    boat.h
)

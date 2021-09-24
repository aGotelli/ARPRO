#cmake_minimum_required(VERSION 2.8)

project(battleship)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(${PROJECT_NAME} "main.cpp"
    src/player.cpp
    include/player.h)

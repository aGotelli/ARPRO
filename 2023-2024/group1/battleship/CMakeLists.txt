cmake_minimum_required(VERSION 3.5)

project(battleship LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

add_library(player
    include/grid.hpp
    include/player.hpp
    src/player.cpp
)


add_executable(battleship
    main.cpp
)
target_link_libraries(battleship player)

cmake_minimum_required(VERSION 3.5)

project(battleship LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(player
    player.hpp
    player.cpp
    ship.hpp
    utility.hpp
    utility.cpp
)



add_executable(battleship
    main.cpp
)
target_link_libraries(battleship
    player
)

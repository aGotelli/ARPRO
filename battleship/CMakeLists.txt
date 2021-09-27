project(battleship)

set(CMAKE_CXX_STANDARD 17)



add_executable(battleship
    board.h
    player.cpp
    player.h
    battleship.cpp)

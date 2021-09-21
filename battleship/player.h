#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <array>
#include <vector>

#include "board.h"

// Second way to define an object
class Player
{
public:
    //  Constructor
    Player();

    //  This is the function declaration
    void displaPlayerGrid();

    std::array<std::array<Box, 10>, 10> player_grid;


};

#endif // PLAYER_H

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
    Player(bool human=true);

    //  This is the function declaration
    void displaPlayerGrid(Player other);

    std::array<std::array<Box, 10>, 10> player_grid;

    void printGridLine(const unsigned int row);

    void shootPlayer(Player& opponent);

    //  Add the default initialized flag
    //  We want to create an human player and a computer-player
    bool is_human { true };


};

#endif // PLAYER_H

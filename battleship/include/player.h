#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <vector>
#include <iostream>

#include "box.h"    //  Double quote to
                    //  Include sth I created


class Player
{
public:
    //  Here we add default value for parameters
    Player(const bool human=true);

    //  Declare that the function exists, inside the class, in the .h
    void showPlayerGrid(Player opponent);

    void printGridLine(const unsigned int row);

    //  We need to take the object as reference because
    //  we want to modify the other player grid.
    //  If we don't use the uppersand "&" we take the
    //  parameter "opponent" as a copy and so, once the
    //  function ends, the copy is deleted.
    void shootAtPlayer(Player &opponent);

    bool isPlayerInGame();


private:
    //  Define if the player is human or not
    const bool is_human { true };
    //  Create a row
    //std::array<int, 10> grid_row;

    //  Default initialization for the grid rows and columns
    const unsigned int columns_number { 10 };
    const unsigned int rows_number { 10 };

    //  Creating the grid
    std::array<std::array<Box, 10>, 10> player_grid;


    std::vector<std::pair<unsigned int,
    unsigned int>> placeBoatRandomly(const unsigned int boat_length);
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <vector>
#include <iostream>

class Player
{
public:
    Player();

    //  Declare that the function exists, inside the class, in the .h
    void showPlayerGrid();


private:
    //  Create a row
    //std::array<int, 10> grid_row;

    //  Creating the grid
    /*
     *
     */
    std::array<std::array<unsigned int, 10>, 10> player_grid;


    std::vector<std::pair<unsigned int,
    unsigned int>> placeBoatRandomly(const unsigned int boat_length);
};

#endif // PLAYER_H

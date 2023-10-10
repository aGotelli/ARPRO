#include <iostream>
#include <vector>

#include "player.hpp"





/*
 * 1) Safe random placement
 * 2) Place all the ships
 * 3) Players interactions
 *
 * 4) std algorithms
 * 5) Code layout
 *
 */




void printGrid(const std::vector<std::vector<char>> t_grid)
{
    for(unsigned int row_index=0; row_index<t_grid.size(); row_index++){
        auto grid_row = t_grid[row_index];

        for(unsigned int col_index=0; col_index<grid_row.size(); col_index++){

            char cell = grid_row[col_index];

            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

}







int main()
{

    Player player1;

    printGrid( player1.m_grid );

    std::cout << "\n\n\n";


    player1.placeShip();


    printGrid( player1.m_grid );


    return 0;
}

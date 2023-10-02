#include <iostream>
#include <vector>

#include "player.hpp"



void printGrid(const std::vector<std::vector<char>> &t_grid)
{
    for(unsigned int row_index=0; row_index<t_grid.size(); row_index++){
        const auto row = t_grid[row_index];

        for(unsigned int col_index=0; col_index<row.size(); col_index++)
            std::cout << row[col_index] << " ";
        std::cout << "\n";
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    Player player;

    player.fleetPlacement();

    printGrid( player.m_grid );

    return 0;
}

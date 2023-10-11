#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <random>
#include <iostream>
#include <vector>

int getRandomInt(const unsigned int t_max)
{
    return rand() % (t_max + 1);
}


void printGrid(const std::vector<std::vector<char>> t_grid)
{
    std::cout << "  ";
    for(unsigned int i=0; i<t_grid[0].size(); i++)
        std::cout << i << " ";
    std::cout << std::endl;

    for(unsigned int row_index=0; row_index<t_grid.size(); row_index++){
        auto grid_row = t_grid[row_index];

        std::cout << row_index << " ";
        for(unsigned int col_index=0; col_index<grid_row.size(); col_index++){

            char cell = grid_row[col_index];

            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}




#endif // UTILITY_HPP

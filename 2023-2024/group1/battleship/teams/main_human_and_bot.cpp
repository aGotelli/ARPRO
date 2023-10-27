#include <iostream>
#include <vector>
#include <player.hpp>
#include <grid.hpp>

using namespace std;

void printGrid(const vector<vector<char>> t_grid)
    {
        for (unsigned int row_index=0; row_index<t_grid.size(); row_index++)
        {
            const auto row = t_grid[row_index];
            for (unsigned int col_index = 0; col_index < t_grid.size(); col_index++)
                cout << row[col_index] << " ";
             cout << "\n";
        }
            cout << "\n" << endl;
    }



int main()
    {
    Human player;
    //Bot bot;

    player.fleetPlacement();
    printGrid(player.m_grid);

  return 0;
    }

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;


int getRandomInInterval(const int t_max)
{
    unsigned seed = static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, t_max);
    int  Generated_num = distribution(generator);

    return Generated_num;
}


struct Ship {

    Ship(const char t_ID,
         const unsigned int t_size,
         const char t_ori)
    {
        m_ID = t_ID;
        m_size = t_size;
        m_orientation = t_ori;
    }

    char m_ID;
    unsigned int m_size;
    char m_orientation;
};


struct Player {

    //  Constructor
    Player()
    {
        //  Defining default row
        std::vector<char> row;
        row.resize(m_grid_cols);

        for(unsigned int it=0; it<row.size(); it++){
            row[it] = 0;
        }

        for(unsigned it=0; it<m_grid_rows; it++)
            m_grid.push_back( row );

        //  Adding a destroyer of size 3
        Ship minesweeper('M', 1 ,'u');
        Ship Destroyer('D', 3,'u');
        Ship Submarine('S', 3,'u');
        Ship Cruiser('C', 4,'u');
        Ship Battleship ('B',5,'u');

        m_fleet.push_back( minesweeper );
        m_fleet.push_back( Destroyer );
        m_fleet.push_back( Submarine);
        m_fleet.push_back( Cruiser );
        m_fleet.push_back( Battleship);


    }


    void fleetPlacement()
    {
        //  Instance of the ship to place
        for(Ship ship : m_fleet){
            //  Place the ship at random coordinates
            //  Place horizontally, in growing columns
            if (getRandomInInterval(2)==1)
            {
                int row_index = getRandomInInterval(9);
                int col_index = getRandomInInterval(m_grid_cols  - (ship.m_size));
                ship.m_orientation = 'H';
                cout << ship.m_orientation << "\n" << endl;

                } else {
                int row_index = getRandomInInterval(m_grid_cols  - (ship.m_size));
                int col_index = getRandomInInterval(9);
                ship.m_orientation = 'V';
                cout << ship.m_orientation << endl;
            }

            /*
             * To Do:
             *
             * 1) Safe placement (while some condition...)
             * 2) All the ships
             * 3) Shooting other player
             * 4) std::algorithms
             * 5) Proficient C++
             *
             */

            //  Place all the characters in the grid
            //for(int it=0; it<ship.m_size; it++)
                //m_grid[row_index][col_index + it] = ship.m_ID;

        }

    }


    //  Default initialisation
    const unsigned int m_grid_rows { 10 };
    const unsigned int m_grid_cols { 10 };

    //  Declaration
    std::vector<std::vector<char>> m_grid;

    std::vector<Ship> m_fleet;
    std::vector<Ship> m_orientation;
};





#endif // PLAYER_HPP

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>


int getRandomInInterval(const int t_max=10)
{
    return rand() % t_max;
}


struct Ship {

    Ship(const char t_ID,
         const unsigned int t_size)
    {
        m_ID = t_ID;
        m_size = t_size;
    }

    char m_ID;
    unsigned int m_size;
};


struct Player {

    //  Constructor
    Player()
    {
        //  Defining default row
        std::vector<char> row;
        row.resize(m_grid_cols);

        for(unsigned int it=0; it<row.size(); it++){
            row[it] = '~';
        }

        for(unsigned it=0; it<m_grid_rows; it++)
            m_grid.push_back( row );

        //  Adding a destroyer of size 3
        Ship destroyer('D', 3);
        Ship cruiser('C', 4);
        Ship minesweeper('M', 1);

        m_fleet.push_back( destroyer );
        m_fleet.push_back( cruiser );
        m_fleet.push_back( minesweeper );

    }


    void fleetPlacement()
    {
        //  Instance of the ship to place
        for(Ship ship : m_fleet){
            //  Place the ship at random coordinates
            //  Place horizontally, in growing columns
            int row_index = getRandomInInterval();
            int col_index = getRandomInInterval(m_grid_cols - (ship.m_size - 1));

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
            for(int it=0; it<ship.m_size; it++)
                m_grid[row_index][col_index + it] = ship.m_ID;

        }

    }


    //  Default initialisation
    const unsigned int m_grid_rows { 10 };
    const unsigned int m_grid_cols { 10 };

    //  Declaration
    std::vector<std::vector<char>> m_grid;

    std::vector<Ship> m_fleet;
};





#endif // PLAYER_HPP

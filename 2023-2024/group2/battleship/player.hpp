#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>


struct Ship {
    Ship(unsigned int t_length,
         char t_ID)
    {
        m_length = t_length;
        m_ID = t_ID;
    }

    unsigned int m_length;
    char m_ID;
};


int getRandomInt(const unsigned int t_max)
{
    return rand() % (t_max + 1);
}



struct Player {

    Player()
    {

        //  Declare a vector of char
        std::vector<char> row;
        row.resize(number_of_cols);

        for(int it=0;
            it<row.size();
            it++)
        {
            row[it] = '~';
        }

        for(unsigned int row_index=0;
            row_index<number_of_rows;
            row_index++)
            m_grid.push_back(row);
    }


    void placeShip()
    {
        Ship ship(3, 'D');

        unsigned int row_begin = getRandomInt(number_of_rows-1);
        unsigned int col_begin = getRandomInt(number_of_cols-1);

        unsigned int horizontal = getRandomInt(1);


        for(unsigned int step=0; step<ship.m_length; step++){

            if(horizontal == 1)
                m_grid[row_begin][col_begin + step] = ship.m_ID;
            else
                m_grid[row_begin + step][col_begin] = ship.m_ID;
        }
    }




    //  Player identifier
    unsigned int m_ID;

    unsigned int number_of_rows { 10 };
    unsigned int number_of_cols { 10 };

    std::vector<std::vector<char>> m_grid;


};









#endif // PLAYER_HPP

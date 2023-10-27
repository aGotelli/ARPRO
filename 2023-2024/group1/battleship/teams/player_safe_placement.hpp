#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>
#include <iostream>

int getRandomInInterval(const int max=10)
{
    srand(4);
    return rand() % max;
}



struct Ship{


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


    //constructor special function
    Player()
    {


        // difining default row
        std::vector<char> row;
        row.resize(m_grid_cols);

        for(unsigned int it=0; it<row.size(); it++){
            row[it] = '~';
        }


        for(unsigned int it=0; it<m_grid_rows; it++)
            m_grid.push_back(row);    //with just one line you can avoid {}

        // adding a ship
        Ship destroyer('D',3);
        Ship cruiser('C',4);
        Ship minesweeper ('M',1);
        Ship aircraft ('A',5);
        Ship submarine ('S',3);


        m_fleet.push_back(destroyer);
        m_fleet.push_back(cruiser);
        m_fleet.push_back(minesweeper);
        m_fleet.push_back(aircraft);
        m_fleet.push_back(submarine);






    }


    void fleetPlacement()
    {
        // instance ofthe ship to place

        for(Ship ship : m_fleet){
            // place the ship ar coordinates (5, 3)
            // place horizontally, in growing columns (on the right)
        if (direction == 'H'){
            int row_index = getRandomInInterval(m_grid_rows - 1);
            int col_index = getRandomInInterval(m_grid_cols - ship.m_size);

            while(check_space(m_grid, row_index, col_index,ship.m_size) != true){
                row_index = getRandomInInterval();
                col_index = getRandomInInterval(m_grid_cols - (ship.m_size - 1));
            }
            for(int it=0; it<ship.m_size; it++)
                m_grid[row_index][col_index+it]=ship.m_ID;
        }

        if (direction == 'V'){
            int row_index = getRandomInInterval(m_grid_rows - ship.m_size);
            int col_index = getRandomInInterval(m_grid_cols - 1);

            while(check_space(m_grid, row_index, col_index,ship.m_size) != true){
                row_index = getRandomInInterval(m_grid_rows - ship.m_size);
                col_index = getRandomInInterval(m_grid_cols - 1);
            }
            for(int it=0; it<ship.m_size; it++)
                m_grid[row_index + it][col_index]=ship.m_ID;
        }


        }
     }


    bool check_space(std::vector<std::vector<char>> t_grid,
                     int t_row_index,
                     int t_col_index,
                     int t_size,
                     char direction){
        int k = 0;

        if (direction == 'H'){
        for (int it=0; it<t_size; it++){

            if (t_grid[t_row_index][t_col_index + it]!='~'){
                k = k + 1;
            }

        }
        if (k != 0) {
            return false;
        }
        else {
            return true;
        }
        }
    }

        if (direction == 'V'){
        for (int it=0; it<t_size; it++){

            if (t_grid[t_row_index+it][t_col_index]!='~'){
                k = k + 1;
            }

        }
        if (k != 0) {
            return false;
        }
        else {
            return true;
        }
        }










    //default initialisation
    const unsigned int m_grid_rows { 10 };
    const unsigned int m_grid_cols { 10 };


    //declaration
    std::vector<std::vector<char>> m_grid;

    std::vector<Ship> m_fleet;



};







#endif // PLAYER_HPP

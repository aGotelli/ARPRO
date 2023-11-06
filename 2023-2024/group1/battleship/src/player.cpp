#include "player.hpp"
#include <algorithm>

Player::Player()
{
    //  Defining default row
    std::vector<char> row;
    row.resize(m_grid_cols);

    for(unsigned int it=0; it<row.size(); it++){
        row[it] = '~';
    }

    for(unsigned it=0; it<m_grid_rows; it++)
        m_grid.push_back( row );


    for(unsigned int it=0; it<row.size(); it++){
        row[it] = '~';
    }

    for(unsigned it=0; it<m_grid_rows; it++)
        m_grid_hidden.push_back( row );

    //  Adding a destroyer of size 3
    Ship minesweeper('M', 1, getRandomInInterval(2)-1);
    Ship Destroyer('D', 3, getRandomInInterval(2)-1);
    Ship Submarine('S', 3, getRandomInInterval(2)-1);
    Ship Cruiser('C', 4, getRandomInInterval(2)-1);
    Ship Battleship ('B',5, getRandomInInterval(2)-1);

    m_fleet.push_back( minesweeper );
    m_fleet.push_back( Destroyer );
    m_fleet.push_back( Submarine);
    m_fleet.push_back( Cruiser );
    m_fleet.push_back( Battleship);


}




void Player::fleetPlacement()
{
    //  Instance of the ship to place
    for(Ship ship : m_fleet){
        //  Place the ship at random coordinates
        //  Place horizontally, in growing columns

        int row_index, col_index;

        getCoordinates(row_index, col_index, ship);


        if (ship.m_horizontal)
        {

            while(check_space(row_index,
                              col_index,
                              ship.m_size,
                              ship.m_horizontal) != true){
                getCoordinates(row_index, col_index, ship);
            }
            for(int it=0; it<ship.m_size; it++)
                m_grid[row_index][col_index+it]=ship.m_ID;


            } else {

            while(check_space(row_index,
                              col_index,
                              ship.m_size,
                              ship.m_horizontal) != true){
                getCoordinates(row_index, col_index, ship);
            }
            for(int it=0; it<ship.m_size; it++)
                m_grid[row_index + it][col_index]=ship.m_ID;
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



void Player::printGrid()
{

    std::cout << "  ";
    for(unsigned int i=0; i<m_grid_cols; i++)
        std::cout << i << " ";
    std::cout << "\n";
    for(unsigned int row_index=0; row_index<m_grid_rows; row_index++){

        const auto row = m_grid[row_index];

        std::cout << row_index << " ";

        for(unsigned int col_index=0; col_index<m_grid_cols; col_index++)
            std::cout << row[col_index]<<" ";
        std::cout << "\n";


    }
    std::cout << "\n"<< std::endl;
}



void Player::shooting(std::shared_ptr<Player> target)
{

    auto [row, col] = generateShootingCoordinates();

    /*check in the actual value of the grid*/
    if(target->m_grid[row][col]=='~')
        m_grid_hidden[row][col] = 'O';
    else
        m_grid_hidden[row][col] = 'X';
}


bool Player::check_space(int t_row_index,
                 int t_col_index,
                 int t_size,
                 bool is_orizontal)
{

    if (is_orizontal){
        auto row = m_grid[t_row_index];
        auto it_begin = row.begin() + t_col_index;
        auto it_end = it_begin + t_size;

        auto lambda = [](char cell)->bool{
            return (cell == '~');
        };

        auto not_sea = std::find_if_not(it_begin,
                                        it_end,
                                        lambda);
        if(not_sea != it_end)
            return false;

        for (int it=0; it<t_size; it++){
            if (m_grid[t_row_index][t_col_index + it]!='~')
                return false;
        }
        return true;
    }else{//  Otherwise is vertical
        for (int it=0; it<t_size; it++){
            if (m_grid[t_row_index+it][t_col_index]!='~')
                return false;
        }
        return true;
    }
}

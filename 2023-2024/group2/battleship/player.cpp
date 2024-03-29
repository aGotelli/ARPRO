#include "player.hpp"


Player::Player()
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


    m_fleet.push_back( Ship(5, 'A') );
    m_fleet.push_back( Ship(4, 'C') );
    m_fleet.push_back( Ship(3, 'D') );
    m_fleet.push_back( Ship(3, 'S') );
    m_fleet.push_back( Ship(2, 'M') );


    for(auto& cell : row)
        cell = '.';


    for(unsigned int row_index=0;
        row_index<number_of_rows;
        row_index++)
        m_opponent_grid.push_back(row);

}



bool Player::checkForFreeCells(const bool t_horizontal,
                               const unsigned int t_row,
                               const unsigned int t_col,
                               const unsigned int t_length)
{
    if(t_horizontal){
        //  Check for horizontal placement
        for(unsigned int iter_col=t_col; iter_col<t_col+t_length; iter_col++){
            if(m_grid[t_row][iter_col] != '~')
                return false;
        }
    }else{
        //  Check for vertical placement
        for(unsigned int iter_row=t_row; iter_row<t_row+t_length; iter_row++){
            if(m_grid[iter_row][t_col] != '~')
                return false;
        }
    }

    return true;
}


void Player::placeShip()
{
    //  Ranged for loop iteratin through all the entries
    for(const Ship ship : m_fleet){

        m_life_points += ship.m_length;

        bool horizontal = getRandomInt(1);

        unsigned int row_begin, col_begin;


        bool keep_placing = true;
        while(keep_placing){

            if(horizontal == 1){
                row_begin = getRandomInt(number_of_rows-1);
                col_begin = getRandomInt(number_of_cols-ship.m_length);
            }else{
                row_begin = getRandomInt(number_of_rows-ship.m_length);
                col_begin = getRandomInt(number_of_cols-1);
            }

            keep_placing = !checkForFreeCells(horizontal,
                                            row_begin,
                                            col_begin,
                                            ship.m_length);
        }


        for(unsigned int step=0; step<ship.m_length; step++){

            if(horizontal == 1)
                m_grid[row_begin][col_begin + step] = ship.m_ID;
            else
                m_grid[row_begin + step][col_begin] = ship.m_ID;
        }
    }
}



void Player::shootAtPlayer(std::shared_ptr<Player> t_opponent)
{
    std::cout << "Player : " << m_ID << " shooting at ";

    //  Get the coordinates for human/bot
    const auto [row, col] = shootAtCoord();

    std::cout << "row:" << row << " col:" << col << "\n";

    //  Check the opponent grid
    const auto opponent_cell = t_opponent->m_grid[row][col];

    std::cout << t_opponent->m_ID << " says: ";
    if(opponent_cell == '~'){
        m_opponent_grid[row][col] = '~';
        std::cout << "You shoot at the sea!" << std::endl;
    } else {
        m_opponent_grid[row][col] = 'X';
        t_opponent->m_life_points --;
        std::cout << "You hit a ship!" << std::endl;
    }
}





std::pair<int, int> Human::shootAtCoord()
{
    unsigned int row, col;

    std::cout << "Enter a row : ";
    std::cin >> row;
    std::cout << "Enter a col : ";
    std::cin >> col;

    return {row, col};
}


std::pair<int, int> Bot::shootAtCoord()
{
    unsigned int row, col;

    row = getRandomInt(number_of_rows-1);
    col = getRandomInt(number_of_cols-1);

    return {row, col};
}




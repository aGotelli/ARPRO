#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "utility.hpp"
#include "ship.hpp"

#include <memory>





struct Player {

    Player();


    bool checkForFreeCells(const bool t_horizontal,
                           const unsigned int t_row,
                           const unsigned int t_col,
                           const unsigned int t_length);


    void placeShip();


    virtual std::pair<int, int> shootAtCoord()=0;


    void shootAtPlayer(std::shared_ptr<Player> t_opponent);




    //  Player identifier
    std::string m_ID;

    unsigned int number_of_rows { 10 };
    unsigned int number_of_cols { 10 };

    std::vector<std::vector<char>> m_grid;

    std::vector<std::vector<char>> m_opponent_grid;



    std::vector<Ship> m_fleet;


    unsigned int m_life_points;


};



struct Human : Player {

    virtual std::pair<int, int> shootAtCoord() override;
};


struct Bot : Player {

    virtual std::pair<int, int> shootAtCoord() override;
};









#endif // PLAYER_HPP

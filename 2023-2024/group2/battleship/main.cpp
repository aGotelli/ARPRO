#include <iostream>
#include <vector>

#include "player.hpp"
#include "utility.hpp"




/*
 * 1) Safe random placement
 * 2) Place all the ships
 * 3) Players interactions
 *
 * 4) std algorithms
 * 5) Code layout
 *
 */












int main()
{

    Player player1("bot 1");
    Player player2("bot 2");




    player1.placeShip();
    player2.placeShip();


    std::cout << "Grids player 1\n";
    printGrid( player1.m_grid );
    printGrid( player1.m_opponent_grid );
    std::cout << "\n";
    std::cout << "Grids player 2\n";
    printGrid( player2.m_grid );
    printGrid( player2.m_opponent_grid );
    std::cout << "\n\n";

    bool keep_playing = true;
    while(keep_playing){

        player1.shootAtPlayer(player2);

        if(player2.m_life_points == 0){
            std::cout << "Player " << player1.m_ID << " won!";
            return 0;
        }

        player2.shootAtPlayer(player1);

        if(player1.m_life_points == 0){
            std::cout << "Player " << player2.m_ID << " won!";
            return 0;
        }

        std::cout << "Grids player 1\n";
        printGrid( player1.m_grid );
        printGrid( player1.m_opponent_grid );
        std::cout << "\n";
        std::cout << "Grids player 2\n";
        printGrid( player2.m_grid );
        printGrid( player2.m_opponent_grid );
        std::cout << "\n\n";


    }





    return 0;
}

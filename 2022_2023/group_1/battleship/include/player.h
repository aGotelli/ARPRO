#ifndef PLAYER_H
#define PLAYER_H


#include "board.h"
#include <vector>

#include <random>

#include <algorithm>

#include <iostream>

struct Player {

    Player()
    {
        for(int i=0; i<10; i++){
            std::vector<Cell> row(10);

            board.push_back(row);
        }

        for(auto ship : fleet){

            bool replace = true;

            int start_row;
            int start_col;

            while(replace){

                replace =false;

                if(ship.is_vertical){
                    start_row = rand() % (10 - (ship.length - 1));
                    start_col = rand() % 10;
                }else{
                    start_row = rand() % 10;
                    start_col = rand() % (10 - (ship.length - 1));
                }


                for(int i =0; i<ship.length; i++){

                    if(ship.is_vertical) {
                        if(board[start_row+i][start_col].content != Content::SEA)
                            replace = true;
                    }else{
                        if(board[start_row][start_col+i].content != Content::SEA)
                            replace = true;
                    }

                }

            }


            if(ship.is_vertical){
                for(int i =0; i<ship.length; i++)
                    board[start_row+i][start_col].content = ship.type;
            }else{
                for(int i =0; i<ship.length; i++)
                    board[start_row][start_col+i].content = ship.type;
            }

        }
    }


    void shootAtPlayer(Player &opponent)
    {
        unsigned int row = rand() % 10;
        unsigned int col = rand() % 10;

        bool generate_random_position = true;
        while(generate_random_position){
            generate_random_position = false;

            if(std::find_if(history.begin(),
                            history.end(),
                            [&](std::pair<unsigned int, unsigned int> element){
                            if(row == element.first || col == element.second)
                                return true;
                            else
                                return false;
                    }) != history.end())
                generate_random_position = true;

        }

        if(opponent.board[row][col].content == Content::SEA)
            std::cout << "Hit the sea" << std::endl;
        else{
            opponent.life_points--;
        }

        history.push_back(
                std::make_pair(row, col)
                    );




    }

    std::vector<Ship> fleet {
        Ship(5, Content::AIRCRAFT),
        Ship(3, Content::DESTROYER),
        Ship(4, Content::SUBMARINE),
        Ship(2, Content::CRUISE)
    };

    int life_points {
        std::accumulate(fleet.begin(),
                        fleet.end(),
                        0, [](const Ship &ship){return ship.length;}
                        )
    };

    std::vector<std::pair<unsigned int, unsigned int>> history;

    std::vector<std::vector<Cell>> board;
};




#endif // PLAYER_H

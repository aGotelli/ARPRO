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

        for(int boat_length : boats_length){

            bool boat_is_vertical = static_cast<bool>( rand() % 2 );

            bool replace = true;

            int start_row;
            int start_col;

            while(replace){

                replace =false;

                if(boat_is_vertical){
                    start_row = rand() % (10 - (boat_length - 1));
                    start_col = rand() % 10;
                }else{
                    start_row = rand() % 10;
                    start_col = rand() % (10 - (boat_length - 1));
                }


                for(int i =0; i<boat_length; i++){

                    if(boat_is_vertical) {
                        if(board[start_row+i][start_col].content != 0)
                            replace = true;
                    }else{
                        if(board[start_row][start_col+i].content != 0)
                            replace = true;
                    }

                }

            }


            if(boat_is_vertical){
                for(int i =0; i<boat_length; i++)
                    board[start_row+i][start_col].content = 1;
            }else{
                for(int i =0; i<boat_length; i++)
                    board[start_row][start_col+i].content = 1;
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

        if(opponent.board[row][col].content == 0)
            std::cout << "Hit the sea" << std::endl;
        else{
            opponent.life_points--;
        }

        history.push_back(
                std::make_pair(row, col)
                    );




    }


    std::vector<int> boats_length {
        2, 3, 3, 4, 5
    };

    int life_points {
        std::accumulate(boats_length.begin(),
                        boats_length.end(),
                        0)
    };

    std::vector<std::pair<unsigned int, unsigned int>> history;

    std::vector<std::vector<Cell>> board;
};




#endif // PLAYER_H

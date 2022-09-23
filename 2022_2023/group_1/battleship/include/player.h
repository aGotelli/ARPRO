#ifndef PLAYER_H
#define PLAYER_H


#include "board.h"
#include <vector>

#include <random>

#include <algorithm>

struct Player {

    Player()
    {
        for(int i=0; i<10; i++){
            std::vector<Cell> row(10);

            board.push_back(row);
        }

        for(int boat_length : boats_length){

            bool replace = true;

            int start_row;
            int start_col;

            while(replace){

                replace =false;

                start_row = rand() % 10;
                start_col = rand() % 10;

                for(int i =0; i<boat_length; i++){

                    if(board[start_row][start_col+i].content != 0)
                        replace = true;
                }

            }
            for(int i =0; i<boat_length; i++)
                board[start_row][start_col+i].content = 1;
        }
    }


    std::vector<int> boats_length {
        2, 3, 3, 4, 5
    };

    std::vector<std::vector<Cell>> board;
};




#endif // PLAYER_H

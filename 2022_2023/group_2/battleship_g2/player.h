#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "boat.h"

#include <iostream>

#include <algorithm>

using namespace std;


static void generateRandomCoordinates(unsigned int &row_begin,
                                      unsigned int &col_begin,
                                      const Boat boat)
{
    if(boat.is_vertical){
        row_begin = rand() % (10 - (boat.length-1));
        col_begin = rand() % 10;
    } else {
        row_begin = rand() % 10;
        col_begin = rand() % (10 - (boat.length-1));
    }
}


static bool cellsAreFree(const unsigned int &row_begin,
                         const unsigned int &col_begin,
                         const Boat boat,
                         vector<vector<std::string>> &board)
{
    if(boat.is_vertical){
        for(int i=0; i<boat.length; i++){
            if(board[row_begin+i][col_begin] != "~"){
                return false;
            }
        }

        return true;
    }

    for(int i=0; i<boat.length; i++){
        if(board[row_begin][col_begin+i] != "~"){
            return false;
        }
    }
    return true;
}

struct Player {


    Player()
    {
        for(const auto boat : list_of_boats){

            unsigned int row_begin;
            unsigned int col_begin;

            generateRandomCoordinates(row_begin, col_begin, boat);


            while(!cellsAreFree(row_begin, col_begin, boat, board)){

                generateRandomCoordinates(row_begin, col_begin, boat);
            }
            placeBoat(row_begin, col_begin, boat, board);
        }
    }


    bool shootAtPlayer(Player &opponent)
    {
        unsigned int row = rand() % 10;
        unsigned int col = rand() % 10;

        while(opponent.board[row][col] == "X"){
            row = rand() % 10;
            col = rand() % 10;
        }

        std::cout << "Shooting at [row, col] : [";
        std::cout << row << ", " << col << "]\n";

        if(opponent.board[row][col] == "~")
            std::cout << "You hit the sea!";
        else {
            std::cout << "You hit an : ";
            std::cout << opponent.board[row][col];

            opponent.life_points--;
        }
        cout << "\n";
        opponent.board[row][col] = "X";

        if(opponent.life_points == 0)
            return true;

        return false;
    }

    void placeBoat(const unsigned int row_begin,
                   const unsigned int col_begin,
                   const Boat boat,
                   vector<vector<std::string>> &board)
    {
        if(boat.is_vertical){
            for(int i=0; i<boat.length; i++){
                board[row_begin+i][col_begin] = boat.type;
            }

        } else {
            for(int i=0; i<boat.length; i++){
                board[row_begin][col_begin+i] = boat.type;
            }
        }
    }

    vector<vector<std::string>> board { [](){
            vector<vector<std::string>> grid(10);

            vector<std::string> row(10);
            for(int j=0; j<row.size(); j++)
                row[j] = "~";

            for(int i=0; i<grid.size(); i++)
                grid[i] = row;


            return grid;
                                }() };

    const vector<Boat> list_of_boats {
        Boat("A", 5),
        Boat("S", 4),
        {"D", 3},
        Boat("C", 2)
    };


    int life_points {

        std::accumulate(list_of_boats.begin(),
                        list_of_boats.end(),
                        0,
                        [](int sum, Boat boat)
                        {return sum + boat.length;}
        )

    };
};

#endif // PLAYER_H

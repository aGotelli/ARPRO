#include <iostream>

#include <vector>


#include <random>

#include "boat.h"

using namespace std;



void printGrid(vector<vector<int>> board)
{
    for(int i=0; i<board.size(); i++){
        auto board_row = board[i];

        for(const int &cell : board_row){
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void placeBoat(const unsigned int row_begin,
               const unsigned int col_begin,
               const Boat boat,
               vector<vector<int>> &board)
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


bool cellsAreFree(const unsigned int &row_begin,
                  const unsigned int &col_begin,
                  const Boat boat,
                  vector<vector<int>> &board)
{
    if(boat.is_vertical){
        for(int i=0; i<boat.length; i++){
            if(board[row_begin+i][col_begin] != 0){
                return false;
            }
        }

        return true;
    }

    for(int i=0; i<boat.length; i++){
        if(board[row_begin][col_begin+i] != 0){
            return false;
        }
    }
    return true;
}


void generateRandomCoordinates(unsigned int &row_begin,
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

int main()
{
    vector<int> row(10);
    vector<vector<int>> board(10);

    for(int i=0; i<board.size(); i++)
        board[i] = row;

    printGrid(board);








    const vector<Boat> list_of_boats {
        Boat(1, 4),
        Boat(2, 3),
        {3, 3},
        Boat(4, 2)
    };

    srand(5);
    for(const auto boat : list_of_boats){

        unsigned int row_begin;
        unsigned int col_begin;

        generateRandomCoordinates(row_begin, col_begin, boat);


        while(!cellsAreFree(row_begin, col_begin, boat, board)){

            generateRandomCoordinates(row_begin, col_begin, boat);
        }
        placeBoat(row_begin, col_begin, boat, board);
    }




    printGrid(board);





    return 0;
}

#include <iostream>

#include <vector>


#include <random>

#include "boat.h"
#include "player.h"

using namespace std;



void printGrid(vector<vector<std::string>> board)
{
    cout << "  ";
    for(int i=0; i<board.size(); i++)
        cout << i <<" ";
    cout << "\n";
    for(int i=0; i<board.size(); i++){
        auto board_row = board[i];

        cout << i << " ";
        for(const auto &cell : board_row){
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << endl;
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







int main()
{
    srand(5);

    Player player1;
    Player player2;



    while(true){

        printGrid(player1.board);
        printGrid(player2.board);

        if(player1.shootAtPlayer(player2)){
            std::cout << "Player 1 won!!" << "\n\n\n";
            break;
        }

        if(player2.shootAtPlayer(player1)){
            std::cout << "Player 2 won!!" << "\n\n\n";
            break;
        }
    }



    return 0;
}

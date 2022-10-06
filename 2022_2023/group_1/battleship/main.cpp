#include <iostream>

#include "include/board.h"

#include "include/player.h"

#include <vector>

using namespace std;



void printGrid(std::vector<std::vector<Cell>> board)
{
    std::cout << "  ";
    for(unsigned int i=0; i<10; i++)
        std::cout << i << " ";

    std::cout << std::endl;
    for(unsigned int i=0; i < board.size(); i++){

        std::cout << i << " ";
        auto row = board[i];

        for(Cell cell : row){
            std::cout << cell.content << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{

    srand(time(nullptr));


    Player player_1;
    Player player_2;
    player_2.is_human = false;

    while(true){
        printGrid(player_1.board);
        std::cout << "\n\n\n" << std::endl;
        printGrid(player_2.board);

        if(player_1.shootAtPlayer(player_2)){
            std::cout << "Player 1 won!!! \n\n";
            return 1;
        }

        if(player_2.shootAtPlayer(player_1)){
            std::cout << "Player 2 won!!! \n\n";
            return 2;
        }

    }





    return 0;
}

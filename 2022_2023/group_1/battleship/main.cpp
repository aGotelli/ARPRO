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


    printGrid(player_1.board);



    return 0;
}

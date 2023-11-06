#include <iostream>
#include <vector>
#include <memory>
#include "player.hpp"


void printPlayerGrids(std::shared_ptr<Player> t_player)
{

    unsigned int number_of_rows = t_player->m_grid_rows;
    unsigned int number_of_cols = t_player->m_grid_cols;

    std::cout << "  ";
    for(unsigned int i=0; i<number_of_cols; i++)
        std::cout << i << " ";
    std::cout << "  ";
    for(unsigned int i=0; i<number_of_cols; i++)
        std::cout << i << " ";
    std::cout << "\n";

    for(unsigned int row_index=0;
        row_index<number_of_rows;
        row_index++){

        std::cout << row_index << " ";

        for(const auto cell : t_player->m_grid[row_index])
            std::cout << cell << " ";

        std::cout << "  ";

        for(const auto cell : t_player->m_grid_hidden[row_index])
            std::cout << cell << " ";

        std::cout << row_index;

        std::cout << "\n";
    }
    std::cout << "\n"<< std::endl;
}






int main()
{
    std::shared_ptr<Player> player1 =
            std::make_shared<Bot>();
    player1->fleetPlacement();
    printPlayerGrids(player1);

    std::shared_ptr<Player> player2 =
            std::make_shared<Human>();
    player2->fleetPlacement();
    printPlayerGrids(player2);

    bool keep_playing = true;
    while(keep_playing){
        printPlayerGrids(player1);
        player1->shooting(player2);

        printPlayerGrids(player2);
        player2->shooting(player1);

    }





    return 0;
}

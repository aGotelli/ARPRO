#include <iostream>
#include <vector>
#include <memory>
#include "player.hpp"


void printPlayerGrids(std::shared_ptr<Player> t_player)
{

    unsigned int number_of_rows = t_player->m_grid_rows;
    unsigned int number_of_cols = t_player->m_grid_cols;


    for(unsigned int row_index=0;
        row_index<number_of_rows;
        row_index++){

        for(const auto cell : t_player->m_grid[row_index])
            std::cout << cell << " ";

        std::cout << "  ";

        for(const auto cell : t_player->m_grid_hidden[row_index])
            std::cout << cell << " ";

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
        player1->shooting(player2);
        printPlayerGrids(player1);
        player2->shooting(player1);
        printPlayerGrids(player2);
    }





    return 0;
}

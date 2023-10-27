#include <iostream>
#include <vector>

#include "player.hpp"

//bool shooting(int shooting_x, int shooting_y, Player target){

//    /*check in the actual value of the grid*/
//    if(target.m_grid[shooting_x][shooting_y]=='~'){
//        return false;

//    }else{
//        return true;
//    }


//    /*print the new grid*/


//}




void printGrid(const std::vector<std::vector<char>> t_grid)
{
    for(unsigned int row_index=0; row_index<t_grid.size(); row_index++){

        const auto row = t_grid[row_index];

        for(unsigned int col_index=0; col_index<row.size(); col_index++)
            std::cout << row[col_index]<<" ";
        std::cout << "\n";


    }
    std::cout << "\n"<< std::endl;
}


int main()
{

    int shooting_x, shooting_y;
    bool shootval;
    Bot player1;
    player1.fleetPlacement();
    printGrid(player1.m_grid);

    Human player2;
    player2.fleetPlacement();
    printGrid(player2.m_grid);

return -1;
    player1.fleetPlacement();




    std::cout<<"Grid Player 1"<<std::endl;

    printGrid(player1.m_grid);

    player2.fleetPlacement();


    std::cout<<"Grid Player 2"<<std::endl;
    printGrid(player2.m_grid_hidden);


    /*player choose his coordinates*/
    std::cout << "Choose cordinate of shooting: [x]: " <<std::endl;
    std::cin >> shooting_x;
    std::cout << "Choose cordinate of shooting: [y]: " <<std::endl;
    std::cin >> shooting_y;

//    shootval = shooting(shooting_x, shooting_y ,player2);

//    if(shootval = true){
//        player2.m_grid_hidden[shooting_x][shooting_y] = '0';
//    }else{
//         player2.m_grid_hidden[shooting_x][shooting_y] = 'x';
//    }

//    printGrid(player2.m_grid);

//    printGrid(player2.m_grid_hidden);




    return 0;
}

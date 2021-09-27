#include "player.h"


int main()
{
    srand( static_cast<unsigned int>(time(nullptr)) );

    Player player1;

    //  Player two will not be an human player
    Player player2(false);


    player1.displaPlayerGrid(player2);

    while (true) {//    For the moment continuously loop and shoot
        player1.shootPlayer(player2);

        player2.shootPlayer(player1);
    }




    return 0;
}

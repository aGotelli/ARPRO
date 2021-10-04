#include <iostream>

#include "player.h"






int main()
{
    //  Get different seed for random number generation
    srand(static_cast<unsigned int>(time(nullptr)));


    Player player1;


    Player player2(false);




    while (true) {  //  Temporaly infinite while loop
        if(player2.isPlayerInGame())
            player1.shootAtPlayer(player2);
        else {
            std::cout << "Player 1 won !" << std::endl;
            break;  //  This will end the while loop
        }

        if(player1.isPlayerInGame())
            player2.shootAtPlayer(player1);
        else {
            std::cout << "Player 2 won !" << std::endl;
            break;  //  This will end the while loop
        }
    }
//                                //  || = OR
//                                //  && = AND
//    while (player1.isPlayerInGame() &&
//           player2.isPlayerInGame()) {

//        player1.shootAtPlayer(player2);

//        player2.shootAtPlayer(player1);
//    }


    return 0;
}




/*
 * Usual layout for a project
 *
 * battleship
 *  |
 *  |-battleship.cpp
 *  |include
 *  |   |
 *  |   |-player.h
 *  |src
 *      |
 *      |-player.cpp
 *
 */





// Define a point in space [x, y, z]
class Point{
public:
    //  Copying values in the constructor
//    Point(const double x_,
//          const double y_,
//          const double z_){
//        x = x_;
//        y = y_;
//        z = z_;
//    }

    Point(){}

    //  Using a list constructor (better and more clean
    Point(const double x_,
          const double y_,
          const double z_) : x(x_), y(y_), z(z_){}


    void print()
    {
        std::cout << "[x, y, z] = [" << x << ", " << y << ", " << z << "]" << std::endl;
    }

private:
    //  These are members variables
    //  In class member initialization
    double x { 0.0 };
    double y { 0.0 };
    double z { 0.0 };
};

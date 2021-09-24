#include <iostream>

#include "player.h"






int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));


    Player test_player_class;

    test_player_class.showPlayerGrid();

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

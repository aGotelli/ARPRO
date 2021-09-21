#include "player.h"


unsigned int getRandomInteger(const unsigned int max)
{
    return static_cast<unsigned int>(rand())%max;
}

Player::Player()
{

    std::vector<std::pair<BoxContent,
            unsigned int>> boats_list {
        {BoxContent::AIRCRAFT, 5},
        {BoxContent::CRUISE, 4},
        {BoxContent::DESTROYER, 3},
        {BoxContent::SUBMARINE, 2}
    };

    for (auto [boat_type, boat_lengh] : boats_list) {
        // and now...
    }

    //  I want to create my boats
    const unsigned int boat_length = 4;

    bool vertical_boat = getRandomInteger(2);

    // We place the boat vertically
    //                      statment ?      if true do this : if false do this
    unsigned int col = vertical_boat ? getRandomInteger(10) : getRandomInteger(10 - boat_length);
    unsigned int row = vertical_boat ? getRandomInteger(10 - boat_length) : getRandomInteger(10);

    for (unsigned int step=0;step<boat_length;step++) {
        player_grid[row][col].content = BoxContent::AIRCRAFT;
        if(vertical_boat)
            row ++; //  Increase the row
        else
            col ++; //  Increase the column
    }


}


void Player::displaPlayerGrid()
{
    std::cout << "  ";
    for (unsigned int col=0;col<10;col++) {
        std::cout << col << " ";
    }

    std::cout << std::endl;

    for (unsigned int row=0;row<10;row++) {
        std::cout << row << " ";

        for (unsigned int col=0;col<10;col++) {
            std::cout << player_grid[row][col].displayBoxContent() << " ";
        }
        std::cout << std::endl;
    }
}

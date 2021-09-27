#include "player.h"


unsigned int getRandomInteger(const unsigned int limit)
{
    return static_cast<unsigned int>(rand()) % limit;
    //  Returns the residual of the division of rand() by limit.
    // rand() generates a random number in between 0 and the "an high number".
    // then you divide this big random integer by limit.
    // The rest can only be between 0 and limit
}

Player::Player()
{
    //  Create a list with all the boats we need to place
    std::vector<std::pair<BoxContent,
            unsigned int>> boats_list {
        //  Every element of the list a pair.
        //  We pair each type of boat with the corresponding length (std::pair...)
        {BoxContent::AIRCRAFT, 5},
        {BoxContent::CRUISE, 4},
        {BoxContent::DESTROYER, 3},
        {BoxContent::SUBMARINE, 2}
    };

    //  Not a good idea if you can use ranged loops is better
    /*
    for(unsigned int index=0; index<boats_list.size(); index++){
        const BoxContent boat_type = boats_list[index].first;
        const unsigned int boat_length = boats_list[index].second;

        //THIS RAW FOR LOOP WILL DO THE SAME THING AS THE RANGED FOR LOOP
    }
    */

    //  Usinig a ranged loop to take info of each element
    for (const auto& [boat_type, boat_length] : boats_list) {
        //  Now we need to place our boats

        bool vertical_boat = getRandomInteger(2);

        // We place the boat vertically
//        //                      statment ?      if true do this : if false do this
//        unsigned int col;// = vertical_boat ? getRandomInteger(10) : getRandomInteger(10 - boat_length);
//        unsigned int row;// = vertical_boat ? getRandomInteger(10 - boat_length) : getRandomInteger(10);

        //  Declare variables before the while loop
        unsigned int row(0), col(0);

        //  Define your condition for the while loop
        bool replace_boat = true;

        while (replace_boat) {

            //  Check if the boat should be vertical or horizontal
            //  And we generate a safe location
            //  Accounting for the boat length, ensures that the
            //  boat is within the grid limits
            if(vertical_boat){
                row = getRandomInteger(10 - boat_length);
                col = getRandomInteger(10);
            } else {    //The boat is horizontal
                col = getRandomInteger(10 - boat_length);
                row = getRandomInteger(10);
            }

            //  Set to false the need to replace the boat
            replace_boat = false;


            //  We step in every cell where the boat should be
            for (unsigned int step=0;step<boat_length;step++) {

                if(player_grid[row][col].content != BoxContent::SEA)
                    replace_boat = true;

                if(vertical_boat)
                    row ++; //  Increase the row
                else
                    col ++; //  Increase the column
            }

        }

        if(vertical_boat)
            row -= boat_length;
        else
            col -= boat_length;


        for (unsigned int step=0;step<boat_length;step++) {
            player_grid[row][col].content = boat_type;
            if(vertical_boat)
                row ++; //  Increase the row
            else
                col ++; //  Increase the column
        }
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

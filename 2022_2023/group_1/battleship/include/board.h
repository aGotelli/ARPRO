#ifndef BOARD_H
#define BOARD_H



/*
 * 0 sea
 * 1 aircraft
 * 2 defender
 *
 *
 */

#include <random>

enum Content {
    SEA,
    DESTROYER,
    AIRCRAFT,
    SUBMARINE,
    CRUISE
};


struct Ship {

    Ship(unsigned int t_length,
         Content t_type)
        : length(t_length),
          type(t_type)
    {}

    unsigned int length;
    Content type;

    bool is_vertical { static_cast<bool>( rand() % 2 ) };
};

struct Cell {

    bool has_been_hit { false };
    Content content;
};



#endif // BOARD_H

#ifndef BOAT_H
#define BOAT_H


#include <random>

struct Boat {

    Boat(int t_type,
         int t_length)
        : type(t_type),
          length(t_length)
    {}

    Boat(int t_type,
         int t_length,
         bool t_is_vertical)
        : type(t_type),
          length(t_length),
          is_vertical(t_is_vertical)
    {}

    const int type;
    const int length;
    const bool is_vertical { static_cast<bool>(rand() % 2) };
};












#endif // BOAT_H

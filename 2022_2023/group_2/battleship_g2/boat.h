#ifndef BOAT_H
#define BOAT_H


#include <random>

struct Boat {

    Boat(std::string t_type,
         int t_length)
        : type(t_type),
          length(t_length)
    {}

    Boat(std::string t_type,
         int t_length,
         bool t_is_vertical)
        : type(t_type),
          length(t_length),
          is_vertical(t_is_vertical)
    {}

    const std::string type;
    const int length;
    const bool is_vertical { static_cast<bool>(rand() % 2) };
};












#endif // BOAT_H

 #ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>
#include <chrono>
#include <iostream>

#include <memory>


static int getRandomInInterval(const int t_max)
{
    unsigned seed = static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, t_max);
    int  Generated_num = distribution(generator);

    return Generated_num;
}

struct Ship {

    Ship(const char t_ID,
         const unsigned int t_size,
         const bool t_ori)
    {
        m_ID = t_ID;
        m_size = t_size;
        m_horizontal = t_ori;
    }

    char m_ID;
    unsigned int m_size;
    bool m_horizontal { true };
};

struct Player {

    //  Constructor
    Player();

    virtual void getCoordinates(int &row, int &col, Ship &ship)=0;

    void fleetPlacement();

    void printGrid();

    virtual std::pair<int, int> generateShootingCoordinates()=0;

    void shooting(std::shared_ptr<Player> target);

    bool check_space(int t_row_index,
                     int t_col_index,
                     int t_size,
                     bool is_orizontal);

    //  Default initialisation
    const unsigned int m_grid_rows { 10 };
    const unsigned int m_grid_cols { 10 };

    //  Declaration
    std::vector<std::vector<char>> m_grid;
    std::vector<std::vector<char>> m_grid_hidden;

    std::vector<Ship> m_fleet;
};



struct Human : Player {

    virtual std::pair<int, int> generateShootingCoordinates()override
    {
        std::pair<int, int> location;

        std::cout << "Row and Column for your shooting : "<< std::endl;
        std::cin >> location.first >> location.second;

        return location;
    }
    virtual void getCoordinates(int &row,
                                int &col,
                                Ship &ship) override
    {
        printGrid();

        std::cout << "Row and Column and Direction for " << ship.m_ID << ": "<< std::endl;
        std::cin >> row >> col >> ship.m_horizontal;
    }

};

struct Bot : Player {

    virtual void getCoordinates(int &row, int &col, Ship &ship) override
    {
        if(ship.m_horizontal){
            row = getRandomInInterval(m_grid_rows - 1);
            col = getRandomInInterval(m_grid_cols - ship.m_size);
        }else {
            row = getRandomInInterval(m_grid_rows - ship.m_size - 1);
            col = getRandomInInterval(m_grid_cols - 1);
        }
    }


    virtual std::pair<int, int> generateShootingCoordinates()override
    {
        int row;
        int col;

        row = getRandomInInterval(m_grid_rows - 1);
        col = getRandomInInterval(m_grid_rows - 1);

        return {row, col};
    }



};



#endif // PLAYER_HPP

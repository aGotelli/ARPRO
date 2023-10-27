#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

int getRandomInInterval(const int t_max)
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
   Player()
   {
       //  Defining default row
       std::vector<char> row;
       row.resize(m_grid_cols);

       for(unsigned int it=0; it<row.size(); it++){
           row[it] = '~';
       }

       for(unsigned it=0; it<m_grid_rows; it++)
           m_grid.push_back( row );

       //  Adding a destroyer of size 3
       Ship Minesweeper('M', 1, getRandomInInterval(2)-1);
       Ship Destroyer('D', 3, getRandomInInterval(2)-1);
       Ship Submarine('S', 3, getRandomInInterval(2)-1);
       Ship Cruiser('C', 4, getRandomInInterval(2)-1);
       Ship Battleship ('B',5, getRandomInInterval(2)-1);

       m_fleet.push_back( Minesweeper );
       m_fleet.push_back( Destroyer );
       m_fleet.push_back( Submarine);
       m_fleet.push_back( Cruiser );
       m_fleet.push_back( Battleship);


   }


   virtual void getCoordinates(int &row, int &col, Ship &ship)=0;


   void fleetPlacement()
   {
       //  Instance of the ship to place
       for(Ship ship : m_fleet){
           //  Place the ship at random coordinates
           //  Place horizontally, in growing columns

           int row_index, col_index;
           bool user_horizontal;

           /*do { // evaluates whether the users value is legal within the given parameters
           if (cin.fail() || (row_index > 9) || (row_index < 0) || (col_index > 9) || (col_index < 0))
                   {
                       cin.clear();
                       cin.ignore(numeric_limits<streamsize>::max(), '\n');
                       cerr << "Illegal input! Please choose again" << endl;
                       continue;
                   }   else {break;}
               } while (true);*/


           getCoordinates(row_index, col_index, ship);


           if (ship.m_horizontal)
           {
               while(check_space(row_index,
                                 col_index,
                                 ship.m_size,
                                 ship.m_horizontal) != true){
                   getCoordinates(row_index, col_index, ship);

               }
               for(int it=0; it<ship.m_size; it++)
                   m_grid[row_index][col_index+it]=ship.m_ID;


               } else {
               while(check_space(row_index,
                                 col_index,
                                 ship.m_size,
                                 ship.m_horizontal) != true){
                   getCoordinates(row_index, col_index, ship);


               }
               for(int it=0; it<ship.m_size; it++)
                   m_grid[row_index + it][col_index]=ship.m_ID;
           }
       }

   }


   bool check_space(int t_row_index,
                    int t_col_index,
                    int t_size,
                    bool is_orizontal)
   {

       if (is_orizontal){
           for (int it=0; it<t_size; it++){
               if (m_grid[t_row_index][t_col_index + it]!='~')
                   return false;
           }
           return true;
       }else{//  Otherwise is vertical
           for (int it=0; it<t_size; it++){
               if (m_grid[t_row_index+it][t_col_index]!='~')
                   return false;
           }
           return true;
       }

   }


   //  Default initialisation
   const unsigned int m_grid_rows { 10 };
   const unsigned int m_grid_cols { 10 };

   //  Declaration
   std::vector<std::vector<char>> m_grid;

   std::vector<Ship> m_fleet;
};



struct Human : Player {

    virtual void getCoordinates(int &row, int &col, Ship &ship) override
    {
        cout << "Row and Column and Direction for " << ship.m_ID << ": "<< endl;
        cin >> row >> col >> ship.m_horizontal;

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



};




#endif // PLAYER_HPP

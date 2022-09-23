#include <iostream>

//  Function signature
/*
 * its return type
 *
 * int -> integer number 1 2 3 89  7854 -85 -96321
 *
 * float/double -> double  1.22  8.69 -4.88
 *
 * void it return nothing
 *
 * name
 *
 *
 * parameters
 *
 *
 */


int simple_math(const int &a,const int &b);



int main()
{


    int number_to_guess = 66;


    bool number_is_found = false;

    int guess_from_user;

    while(number_is_found == false){


        std::cout << "Guess the number \n";

        std::cin >> guess_from_user;

        if(guess_from_user == number_to_guess)
            number_is_found = true;

        if(guess_from_user < number_to_guess) {
            std::cout << "The number is greater then " << guess_from_user << "\n";
        } else {
            std::cout << "The number is smaller then " << guess_from_user << "\n";
        }

    }






    return 0;
}



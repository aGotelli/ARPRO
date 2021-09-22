#include <iostream>

#include <random>


int main()
{
    std::random_device device;

    std::mt19937 generator(device());

    auto dice(std::uniform_int_distribution<>(1, 100));

    // Number to guess between 0 and 100
    const int number_to_guess(dice(generator));

    std::cout << "The number i generated is :" << number_to_guess << std::endl;


    // Good practice to declare variable before the loop
    int user_guess;


    // Compare our guess with the actual number
    while(true){

        // Get the user guess
        std::cout << "Try to guess the number" << std::endl;
        std::cin >> user_guess;


        // An answer if it is smaller
        if(user_guess < number_to_guess)
            std::cout << "My number is bigger..." << std::endl;
        // Another one if it is bigger
        else if(user_guess > number_to_guess)
            std::cout << "My number is smaller..." << std::endl;
        else if(user_guess == number_to_guess){
            // A compliment if we got it
            std::cout << "You got it!" << std::endl;
            // break to break the loop
            break;
        }
    }




    return 0;
}







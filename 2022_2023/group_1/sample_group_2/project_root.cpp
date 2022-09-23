#include <iostream>




int main()
{

    const int number_to_guess = 66;


    int user_guess;

    std::cout << "Guess the number " << std::endl;
    std::cin >> user_guess;
    bool keep_plying = true;

    while(keep_plying){
        if(user_guess == number_to_guess){
            std::cout << "Good !" << std::endl;
            keep_plying = false;
            break;
        }


        if(user_guess > number_to_guess) {
            std::cout << "The number is smaller" << std::endl;
        }else{
            std::cout << "The number is bigger" << std::endl;
        }
    }








    return 0;
}

#include <iostream>
#include <random>


int main()
{
    // First we generate a random number
    std::random_device device;

    std::mt19937 generator(device());

    // Limit of the guessing process
    int min = 1;
    int max = 100;

    auto dice(std::uniform_int_distribution<>(min, max));

    // Number to guess between 0 and 100
    int current_guess(dice(generator));

    bool keep_guessing = true;

    while(keep_guessing){

        // Ask user about the number
        std::cout << "Is " << current_guess << " your number?" << std::endl;
        std::cout << "My number is : 0 bigger, 1 smaller, 2 ok" << std::endl;
        int user_answer;
        std::cin >> user_answer;

        // Case the user has found the number
        if(user_answer == 2){
            std::cout << "Good!!" << std::endl;
//            keep_guessing = false;
            break;
        } else {

            if(min >= max){
                std::cout << "You are cheating!" << std::endl;
                break;
            }

            //  If the current guess is smaller then the
            //  real number
            if(user_answer == 0) {
                //  Change the lower limit
                min = current_guess + 1;

                // Generate again a guess
                dice = std::uniform_int_distribution<>(min, max);
            }

            if(user_answer == 1) {
                //  Change the lower limit
                max = current_guess - 1;

                // Generate again a guess
                dice = std::uniform_int_distribution<>(min, max);
            }

            //  Change the guess
            current_guess = dice(generator);
        }
    }

    int final_guess = current_guess;

    std::cout << "Here is the final guess : " << final_guess << std::endl;

}

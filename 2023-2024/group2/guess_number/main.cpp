#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



bool keep_playing = true;



int guessInRange(const int t_min,
                 const int t_max)
{
    const int upper_bound = t_max + 1 - t_min;

    const int guess = rand() % upper_bound;

    return guess + t_min;
}


void printGuess(const int t_guess)
{
    cout << "Computer guess : " << t_guess;
    cout << "\n\n" << endl;
}

char processUserInput(int t_min,
                      int t_max,
                      const int t_guess)
{
    cout << "Write + for bigger, - for smaller or = if correct";
    cout << endl;
    //  A string to contain the user input
    char user_input;

    //  Copy the console input in this variable
    cin >> user_input;

    //  Vector of the availble choises for the user
    const vector<char> available_choices { '+', '-', '=' };

    //  Check if the user input is correct
    auto pos = std::find(available_choices.begin(),
                        available_choices.end(),
                        user_input);

    if(pos == available_choices.end())
        processUserInput(t_min, t_max, t_guess);




    switch (user_input) {
        case '+':
            //  Case the number is bigger
            t_min = t_guess + 1;
        break;
        case '-':
            //  Case the number is smaller
            t_max = t_guess - 1;
        break;
        case '=':
            //  Computer won
            cout << "I won! \n";
            keep_playing = false;
        break;
    }


//    //  Checks the user input
//    //  Allowed char + - =
//    switch (user_input) {
//        case '+':
//        case '-':
//        case'=':
//            return user_input;
//        break;
//        default:
//            cout << "Input is wrong !" <<endl;
//            user_input = getUserInput();
//    }

    return user_input;
}


int main()
{

    srand( 1 );

    //  Guess numbers from 1-100
    int min = 1;
    int max = 100;

    int guess = 0;
    //  Computer guess the first number




    while(keep_playing){

        guess = guessInRange(min, max);

        printGuess(guess);

        processUserInput(min,
                         max,
                         guess);

        if(min == max){
            cout << "ERROR: boundaries are inconsitent!\n"
                    "min >= max" << endl;
            return -1;
        }
    }




    return 0;
}

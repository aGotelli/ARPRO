#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool keep_playing = true;

char guessUserNumber(const int t_middle_point)
{
    std::cout << "Is the number smaller bigger or equal of : "
              << t_middle_point << " ? [-, +, =]" << "\n";
    std::cout << std::endl;

    char user_input = 'c';
    std::cin >> user_input;

    return user_input;
}


void processUserInput(char t_user_input,
                      const int &t_middle_point,
                      int &t_min,
                      int &t_max)
{
    std::vector<char> available_choices {
        '+',  '-',  '='
    };
    //  find user input in the available choices
    auto pos = std::find(available_choices.begin(),
              available_choices.end(),
              t_user_input);
    //  If its end it is not in the vector
    if(pos == available_choices.end()){
        std::cout << "Wrong input" << std::endl;

        t_user_input = guessUserNumber(t_middle_point);

        //  Recall the same function (recursive)
        processUserInput(t_user_input,
                         t_middle_point,
                         t_min,
                         t_max);
    }




    if(t_user_input == '+'){
        t_min = t_middle_point;
    }

    if(t_user_input == '-'){
        t_max = t_middle_point;
    }

    if(t_user_input == '='){
        std::cout << "I won!" << std::endl;
        keep_playing = false;
    }

//        switch (user_input) {
//            case '+':
//                min = middle_point;
//            break;
//            case '-':
//                max = middle_point;
//                break;
//            case '=':
//                std::cout << "I won!" << std::endl;
//                keep_playing = false;
//            break;
//            default:
//                std::cout << "Wrong input" << std::endl;
//        }
}


int main()
{

    int min = -10;
    int max = 100;


    while(keep_playing){
        int middle_point = (max + min) / 2;

        auto user_input = guessUserNumber(middle_point);

        std::cout << "min : " << min << " max : " << max << "\n";
        processUserInput(user_input,
                         middle_point,
                         min,
                         max);
        std::cout << "min : " << min << " max : " << max << "\n";
        std::cout << std::endl;

    }

    return 0;
}

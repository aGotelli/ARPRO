#include <iostream>

using namespace std;


int simple_function()
{
    return 5;
}


int main()
{

    //  declaration
    int a;

    a = simple_function();

    double number_with_decimal_points = -32.14;
    std::cout << "a = " << a << " number_with_decimal_points = " << number_with_decimal_points;
    cout << endl;
    return 0;
}

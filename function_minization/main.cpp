#include <iostream>

using namespace std;


//  Global variable are available everywhere in your file
static double a;
static double b;
static double c;

//  Creating a function
/*
 * What is its output
 * The name
 * The input(s)
 */
double f(const double x)
{
    double f_x = a*x*x + b*x + c;

    return f_x;
}

double df(const double x)
{
    //  operations can be done directly in the return (if easy)
    return 2*a*x + b;
}


int main()
{
    a = 5;
    b = 4;
    c = 3;

    double x = 3.0;

    double lambda = 0.1;


    double dx_min = 0.0001;
    double dx = dx_min*2;

            //  Take absolute value as dx could be negative
    while(abs(dx) > dx_min){
        cout << "I am trying with x = " << x << endl;
        dx = lambda*df(x);

        x -= dx;
    }
    cout << endl << endl;
    cout << "We obtained x = " << x << endl;
    cout << "That corrispond to f(x) = " << f(x) << endl;
    cout << "The theoretical minima is x = " << -b/(2*a) << endl; // Be careful in your tests

    return 0;
}

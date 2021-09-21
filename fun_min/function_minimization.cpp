#include <iostream>
static double a, b, c;

// f(x) = a x^2 + b x + c
double f(const double x)
{
    double f = a*x*x + b*x + c;
    return f;
}



double df(const double x)
{
    return 2*a*x + b;
}

int main()
{
    a = 4;
    b = 5;
    c = 3;

    double x = 3.0;
    double dx_min = 0.0001;

    double dx = 2*dx_min;
    double lambda = 0.1;

    while(std::abs(dx) > dx_min) {

        std::cout << "I am evaluating x : " << x << std::endl;

        dx = lambda*df(x);

        x -= dx;
    }

    std::cout << "The function minima is at x = " << -b/(2*a) << std::endl;
    std::cout << "I found the value x = " << x << std::endl;
    std::cout << "For which the function if f(x) = " << f(x) << std::endl;














}

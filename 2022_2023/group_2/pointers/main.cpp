#include <iostream>

using namespace std;

#include <random>

#include <memory>

void f(std::shared_ptr<int> ptr_a)
{
    std::cout << "Count : " << ptr_a.use_count() << std::endl;
}

void f_unique(std::unique_ptr<int> int_ptr)
{
    *int_ptr = -9;
}

//void f(int* ptr_a)
//{
//    *ptr_a++;

//    delete ptr_a;
//}


struct Point {

    Point()=default;

    Point(double t_x,
          double t_y)
        : x(t_x),
          y(t_y)
    {}

    double x {0.0};
    double y {0.0};
};

int main()
{
    int a=0;
    std::shared_ptr<int> integer_ptr;
    integer_ptr = std::make_shared<int>(a);

    std::cout << "Count : " << integer_ptr.use_count() << std::endl;

    f(integer_ptr);

    std::cout << "Count : " << integer_ptr.use_count() << std::endl;


    std::unique_ptr<int> unique_int_ptr = std::make_unique<int>();
    f_unique(std::move(unique_int_ptr));

//    int a = rand() % 10;
//    int* integer_ptr = new int();
//    integer_ptr = &a;

//    cout << "a = " << a << endl;

//    int b = *integer_ptr;
//    *integer_ptr = -89;

//    cout << "a = " << a << endl;

//    delete integer_ptr;

    std::shared_ptr<Point> point_ptr =
            std::make_shared<Point>();

    auto point_ptr2 = std::make_shared<Point>(2, -9);

    return 0;
}

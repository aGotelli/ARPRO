#include <iostream>

#include <memory>

using namespace std;


struct Point {

    Point()=default;

    Point(double t_x,
          double t_y,
          double t_z)
        : x(t_x),
          y(t_y),
          z(t_z)
    {}

    double x { 0.0 };
    double y { 0.0 };
    double z { 0.0 };
};



//void doStuff(int* t_a)
//{
//    delete t_a;
//}

void smartDoStuff(std::shared_ptr<Point> t_shared_ptr)
{
    std::cout << "Counter : " << t_shared_ptr.use_count() << std::endl;

    t_shared_ptr->x = -9;
    t_shared_ptr->y++;
    t_shared_ptr->z--;
}


int main()
{
    int a = 12;

    Point point;

    auto point_ptr = std::make_shared<Point>();
    point_ptr = std::make_shared<Point>(1, 2, 3);

    point_ptr->y = 85;

    std::cout << "Counter : " << point_ptr.use_count() << std::endl;

    smartDoStuff(point_ptr);

    std::cout << "Counter : " << point_ptr.use_count() << std::endl;


//    std::unique_ptr<int> unique_ptr = std::make_shared<int>();

    return 0;
}

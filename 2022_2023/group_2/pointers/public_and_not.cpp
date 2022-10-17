
#include <iostream>
struct Point {
public:
    Point()=default;

    Point(double t_x,
          double t_y)
        : x(t_x),
          y(t_y)
    {}

    double getX() {return x;}


//private:
    virtual void print()=0;
public:
    double x {0.0};

protected:
    double y {0.0};
};


//void Point::print()
//{
//    std::cout << "[x, y] = [" << x << ", " << y << "]" << std::endl;
//}



struct Point2D : public Point {

    Point2D()=default;

    Point2D(double x,
            double y,
            double theta)
        : Point(x, y),
          m_theta(theta)
    {}

    void printY()
    {
        std::cout << y << std::endl;
        //std::cout << x << std::endl;
    }

    virtual void print()override;


    double m_theta{0.0};

};

void Point2D::print()
{
    std::cout << "[x, y, theta] = [" << x << ", " << y << ", " << m_theta <<"]" << std::endl;
}

class Point3D : public Point {
public:
    Point3D(double x,
            double y,
            double z,
            double theta)
        : Point(x, y),
          m_theta(theta),
          m_z(z)
    {}

    virtual void print()override
    {
        std::cout << "[x, y, z, theta] = [" << x << ", " << y << ", " << m_z << ", " << m_theta <<"]" << std::endl;
    }
    double m_theta{0.0};
    double m_z;
};



#include <math.h>
#include <memory>
int main(int argc, char *argv[])
{
    std::shared_ptr<Point> point_ptr;// = std::make_shared<Point>(2.0, -98);

    point_ptr = std::make_shared<Point2D>(-2, -6, M_PI);

    point_ptr->print();

    point_ptr = std::make_shared<Point3D>(-2, -6, 78, M_PI);

    point_ptr->print();

    //point.print();

//    auto x = point->getX();

//    Point2D point2d;
//    point2d.getX();

//    point2d = Point2D(-2, -6, M_PI);

//    point2d.print();


    return 0;
}

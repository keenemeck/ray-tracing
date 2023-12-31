#ifndef point_h
#define point_h

#include <iostream>

#include "vec3.h"

class Vector;

class Point {

friend std::ostream& operator<<(std::ostream& stream, Point& p);

private:

    double a[3];

public:

    Point();
    Point(double x, double y, double z);

    double get_x();
    double get_y();
    double get_z();

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    Point operator+(const Point& p);
    Point operator-(const Point& p);

    Vector to_vector();

};

#endif
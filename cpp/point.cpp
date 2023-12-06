#include "point.h"

// Default constructors for points
Point::Point() : a{0, 0, 0} {}
Point::Point(double _x, double _y, double _z) : a{_x, _y, _z} {}

// Override << operator
std::ostream& operator<<(std::ostream& stream, Point& point) {

    stream << point.a[0] << ' ' << point.a[1] << ' ' << point.a[2] << ' ';
    return stream;

}


// Point getters
double Point::get_x() { return a[0]; }
double Point::get_y() { return a[1]; }
double Point::get_z() { return a[2]; }

// Point setters
void Point::set_x(double x) { this->a[0] = x; }
void Point::set_y(double y) { this->a[1] = y; }
void Point::set_z(double z) { this->a[2] = z; }

Point Point::operator+(const Point& p) { return {a[0] + p.a[0], a[1] + p.a[1], a[2] + p.a[2]}; }
Point Point::operator-(const Point& p) { return {a[0] - p.a[0], a[1] - p.a[1], a[2] - p.a[2]}; }

Vector Point::to_vector() { return {a[0], a[1], a[2]}; }
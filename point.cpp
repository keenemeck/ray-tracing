#include "point.h"

// Default constructors for points
Point::Point() : x(0), y(0), z(0) {}
Point::Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

// Point getters
double Point::get_x() { return x; }
double Point::get_y() { return y; }
double Point::get_z() { return z; }

// Point setters
void Point::set_x(double x) { this->x = x; }
void Point::set_y(double y) { this->y = y; }
void Point::set_z(double z) { this->z = z; }

Point Point::operator+(Point p) { return {x + p.x, y + p.y, z + p.z}; }
#include "vec3.h"

// Default constructors for vectors
Vector::Vector() : i(0), j(0), k(0) {}
Vector::Vector(double _i, double _j, double _k) : i(_i), j(_j), k(_k) {}

// Vector getters
double Vector::get_i() { return i; }
double Vector::get_j() { return j; }
double Vector::get_k() { return k; }

// Vectors setters
void Vector::set_i(double i) { this->i = i; }
void Vector::set_j(double j) { this->j = j; }
void Vector::set_k(double k) { this->k = k; }


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


// Default constructors for colors
Color::Color() : r(0), g(0), b(0) {}
Color::Color(double _r, double _g, double _b) : r(_r), g(_g), b(_b) {}

// Colors getters
double Color::get_r() { return r; }
double Color::get_g() { return g; }
double Color::get_b() { return b; }

// Color setters
void Color::set_r(double r) { this->r = r; }
void Color::set_g(double g) { this->g = g; }
void Color::set_b(double b) { this->b = b; }
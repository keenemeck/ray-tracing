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

Vector Vector::operator+(Vector v) { return {i + v.i, j + v.j, k + v.k}; }
Vector Vector::operator-(Vector v) { return {i - v.i, j - v.j, k - v.k}; }
Vector Vector::operator*(double x) { return {i * x, j * x, k * x}; }
Vector Vector::operator/(double x) { return {i / x, j / x, k / x}; }

Point Vector::to_point() { return {i, j, k}; }

Vector Vector::unit() {

    double magnitude = i * i + j * j + k * k;
    return {i / magnitude, j / magnitude, k / magnitude};

}
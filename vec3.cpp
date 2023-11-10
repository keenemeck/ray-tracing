#include "vec3.h"

// Default constructors for vectors
Vector::Vector() : i(0), j(0), k(0) {}
Vector::Vector(double _i, double _j, double _k) : i(_i), j(_j), k(_k) {}

// Override << operator
std::ostream& operator<<(std::ostream& stream, Vector vec) {

    stream << vec.i << "i " << vec.j << "j " << vec.k << "k";
    return stream;

}

Vector operator-(Vector vec) { return {-vec.i, -vec.j, -vec.k}; }

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

    double magnitude = sqrt(i * i + j * j + k * k);
    return {i / magnitude, j / magnitude, k / magnitude};

}

double Vector::dot(Vector v) { return i * v.i + j * v.j + k * v.k; }

Vector Vector::reflect(Vector v) { return *this - v * 2 * this->dot(v); }

bool Vector::near_zero() {

    double zero = 0.00000001;

    return (fabs(i) < zero) && (fabs(j) < zero) && (fabs(k) < zero);

}
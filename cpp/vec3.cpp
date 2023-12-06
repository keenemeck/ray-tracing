#include "vec3.h"

// Default constructors for vectors
Vector::Vector() : a{0, 0, 0} {}
Vector::Vector(double _i, double _j, double _k) : a{_i, _j, _k} {}

// Override << operator
std::ostream& operator<<(std::ostream& stream, Vector vec) {

    stream << vec.a[0] << "i " << vec.a[1] << "j " << vec.a[2] << "k";
    return stream;

}

Vector operator-(const Vector& vec) { return {-vec.a[0], -vec.a[1], -vec.a[2]}; }
Vector operator+(const Vector& v, const Vector& u) { return {v.a[0] + u.a[0], v.a[1] + u.a[1], v.a[2] + u.a[2]}; }
Vector operator-(const Vector& v, const Vector& u) { return {v.a[0] - u.a[0], v.a[1] - u.a[1], v.a[2] - u.a[2]}; }
Vector operator*(double x, const Vector& v) { return {x * v.a[0], x * v.a[1], x * v.a[2]}; }
Vector operator*(const Vector& v, double x) { return x * v; }
Vector operator/(const Vector& v, double x) { return { (1 / x) * v}; }

Vector reflect(Vector& v, Vector& n) {

    return v - 2 * v.dot(n) * n;

}

// Vector getters
double Vector::get_i() { return a[0]; }
double Vector::get_j() { return a[1]; }
double Vector::get_k() { return a[2]; }

// Vectors setters
void Vector::set_i(double i) { this->a[0] = i; }
void Vector::set_j(double j) { this->a[1] = j; }
void Vector::set_k(double k) { this->a[2] = k; }

Vector Vector::operator+(const Vector& v) { return {a[0] + v.a[0], a[1] + v.a[1], a[2] + v.a[2]}; }
Vector Vector::operator-(const Vector& v) { return {a[0] - v.a[0], a[1] - v.a[1], a[2] - v.a[2]}; }
Vector Vector::operator*(double x) { return {a[0] * x, a[1] * x, a[2] * x}; }
Vector Vector::operator/(double x) { return {a[0] / x, a[1] / x, a[2] / x}; }

Point Vector::to_point() { return {a[0], a[1], a[2]}; }

Vector Vector::unit() {

    double magnitude = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    return {a[0] / magnitude, a[1] / magnitude, a[2] / magnitude};

}

double Vector::dot(const Vector& v) { return a[0] * v.a[0] + a[1] * v.a[1] + a[2] * v.a[2]; }

Vector Vector::reflect(const Vector& v) { return *this - v * 2 * this->dot(v); }

Vector Vector::refract(const Vector& normal, double eta_ratio) {

    double cos_theta = std::min(this->dot(-normal), 1.0);

    Vector perpendicular = (*this + normal * cos_theta) * eta_ratio;
    Vector parallel = normal * -sqrt(fabs(1.0 - perpendicular.dot(perpendicular)));

    return perpendicular + parallel;

}

bool Vector::near_zero() {

    double zero = 0.00000001;

    return (fabs(a[0]) < zero) && (fabs(a[1]) < zero) && (fabs(a[2]) < zero);

}
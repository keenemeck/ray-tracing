#ifndef vec3_h
#define vec3_h

#include "point.h"
#include <iostream>

class Point;

class Vector {

friend std::ostream& operator<<(std::ostream& stream, Vector vec);
friend Vector operator-(const Vector& vec);
friend Vector operator+(const Vector& v, const Vector& u);
friend Vector operator-(const Vector& v, const Vector& u);
friend Vector operator*(double x, const Vector& v);
friend Vector operator*(const Vector& v, double x);
friend Vector operator/(const Vector& v, double x);
friend Vector reflect(const Vector& v, const Vector& n);

private:

    double a[3];

public:

    Vector();
    Vector(double i, double j, double k);

    double get_i();
    double get_j();
    double get_k();

    void set_i(double i);
    void set_j(double j);
    void set_k(double k);

    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector operator*(double x);
    Vector operator/(double x);
    Point to_point();

    Vector unit();
    double dot(const Vector& v);
    Vector reflect(const Vector& v);
    Vector refract(const Vector& normal, double eta_ratio);

    bool near_zero();

};




#endif
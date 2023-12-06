#ifndef color_h
#define color_h

#include "interval.h"

#include <iostream>

class Color {

public:

    Color();
    Color(double r, double g, double b);

    double get_r();
    double get_g();
    double get_b();

    void set_r(double r);
    void set_g(double g);
    void set_b(double b);

    void write_color(std::ostream &out, int samples);

    Color operator*(double x);
    Color operator*(Color& c);
    Color operator+(Color& c);

private:

    double a[3];

};

#endif
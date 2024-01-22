#include "color.h"
#include <cmath>

// Default constructors for colors
Color::Color() : a{0, 0, 0} {}
Color::Color(double _r, double _g, double _b) : a{_r, _g, _b} {}

// Colors getters
double Color::get_r() { return a[0]; }
double Color::get_g() { return a[1]; }
double Color::get_b() { return a[2]; }

// Color setters
void Color::set_r(double r) { this->a[0] = r; }
void Color::set_g(double g) { this->a[1] = g; }
void Color::set_b(double b) { this->a[2] = b; }

Color Color::operator*(double x) { return {a[0] * x, a[1] * x, a[2] * x}; }
Color Color::operator*(Color& c) { return {a[0] * c.a[0] / 255, a[1] * c.a[1] / 255, a[2] * c.a[2] / 255}; }
Color Color::operator+(Color& c) { return {a[0] + c.a[0], a[1] + c.a[1], a[2] + c.a[2]}; }

void Color::write_color(std::ostream &out, int samples) {

    double factor = 1.0 / samples;

    a[0] *= factor;
    a[1] *= factor;
    a[2] *= factor;

    // Default gamma is 1 / 2.2, but this looks wrong to me
    double gamma = 1 / 2.2;

    // linear -> gamma
    a[0] = 255 * std::pow(a[0] / 255, gamma);
    a[1] = 255 * std::pow(a[1] / 255, gamma);
    a[2] = 255 * std::pow(a[2] / 255, gamma);

    Interval rgb(0, 255);

    out << round(rgb.clamp(a[0])) << ' ' << round(rgb.clamp(a[1])) << ' ' << round(rgb.clamp(a[2])) << ' ';

}

#include "color.h"

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

Color Color::operator*(double x) { return {r * x, g * x, b * x}; }
Color Color::operator*(Color& c) { return {r * c.r / 255, g * c.g / 255, b * c.b / 255}; }
Color Color::operator+(Color& c) { return {r + c.r, g + c.g, b + c.b}; }

void Color::write_color(std::ostream &out, int samples) {

    double factor = 1.0 / samples;

    r *= factor;
    b *= factor;
    g *= factor;

    double gamma = 1 / 2.2;

    // linear -> gamma
    r = 255 * pow(r / 255, gamma);
    g = 255 * pow(g / 255, gamma);
    b = 255 * pow(b / 255, gamma);

    Interval rgb(0, 255);

    out << round(rgb.clamp(r)) << ' ' << round(rgb.clamp(g)) << ' ' << round(rgb.clamp(b)) << ' ';

}
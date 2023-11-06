#include "color.h"

// Default constructors for colors
Color::Color() : r(0), g(0), b(0) {}
Color::Color(double _r, double _g, double _b) : r(_r), g(_g), b(_b) {}

// Override << operator
std::ostream& operator<<(std::ostream& stream, Color& color) {

    stream << color.r << ' ' << color.g << ' ' << color.b << ' ';
    return stream;

}

// Colors getters
double Color::get_r() { return r; }
double Color::get_g() { return g; }
double Color::get_b() { return b; }

// Color setters
void Color::set_r(double r) { this->r = r; }
void Color::set_g(double g) { this->g = g; }
void Color::set_b(double b) { this->b = b; }
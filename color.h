#ifndef color_h
#define color_h

#include <iostream>

class Color {

friend std::ostream& operator<<(std::ostream& stream, Color& c);

private:

    double r, g, b;

public:

    Color();
    Color(double r, double g, double b);

    double get_r();
    double get_g();
    double get_b();

    void set_r(double r);
    void set_g(double g);
    void set_b(double b);

    Color operator*(double x);

};

#endif
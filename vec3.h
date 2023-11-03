#ifndef vec3_h
#define vec3_h

class Vector {

private:

    double i, j, k;

public:

    Vector();
    Vector(double i, double j, double k);

    double get_i();
    double get_j();
    double get_k();

    void set_i(double i);
    void set_j(double j);
    void set_k(double k);

};

class Point {

private:

    double x, y, z;

public:

    Point();
    Point(double x, double y, double z);

    double get_x();
    double get_y();
    double get_z();

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

};

class Color {

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

};




#endif
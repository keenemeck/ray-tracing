#ifndef point_h
#define point_h

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

    Point operator+(Point p);

};

#endif
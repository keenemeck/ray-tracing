#ifndef hitInfo_h
#define hitInfo_h

#include "point.h"
#include "vec3.h"
#include "material.h"

class HitInfo {

public:

    HitInfo();

    Point get_point();
    Vector get_normal();
    double get_t();
    bool get_front();
    Material get_material();

    void set_point(Point& p);
    void set_normal(Vector& n);
    void set_t(double _t);
    void set_front(bool f);
    void set_material(Material& m);

private:

    Point point;
    Vector normal;
    double t;
    bool front;
    Material& material;

};


#endif
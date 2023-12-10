#ifndef aabb_h
#define aabb_h

#include "interval.h"
#include "point.h"
#include "ray.h"

class Ray;

class aabb {

public:

    aabb() {}
    aabb(Interval x, Interval y, Interval z);
    aabb(Point a, Point b);
    aabb(aabb& a, aabb& b);

    Interval axis(int n);

    bool hit(Ray& r, Interval& interval);

    Interval get_x();
    Interval get_y();
    Interval get_z();

private:

    Interval x, y, z;

};



#endif
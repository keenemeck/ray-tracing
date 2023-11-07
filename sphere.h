#ifndef sphere_h
#define sphere_h

#include "point.h"
#include "ray.h"
#include "hitInfo.h"
#include "interval.h"

class Sphere {

public:

    Sphere();
    Sphere(Point origin, double radius);

    Point get_origin();
    double get_radius();

    bool ray_collide(Ray& r, Interval& interval, HitInfo& hit);

private:

    Point origin;
    double radius;

};


#endif
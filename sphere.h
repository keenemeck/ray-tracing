#ifndef sphere_h
#define sphere_h

#include "point.h"
#include "ray.h"
#include "hitInfo.h"


class Sphere {

public:

    Sphere();
    Sphere(Point origin, double radius);

    Point get_origin();
    double get_radius();

    bool ray_collide(Ray& r, double t_min, double t_max, HitInfo& hit);

private:

    Point origin;
    double radius;

};


#endif
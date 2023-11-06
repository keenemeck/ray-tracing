#ifndef sphere_h
#define sphere_h

#include "point.h"
#include "ray.h"


class Sphere {

public:

    Sphere();
    Sphere(Point origin, double radius);

    Point get_origin();
    double get_radius();

    double ray_collide(Ray& r);

private:

    Point origin;
    double radius;

};


#endif
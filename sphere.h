#ifndef sphere_h
#define sphere_h

#include "point.h"
#include "ray.h"
#include "hitInfo.h"
#include "interval.h"

#include <vector>

class Ray;

class Sphere {

public:

    Sphere();
    Sphere(Point origin, double radius);

    Point get_origin();
    double get_radius();

private:

    Point origin;
    double radius;

};

bool ray_collide(Ray& r, Interval& interval, std::vector<Sphere>& spheres, HitInfo& hit);


#endif
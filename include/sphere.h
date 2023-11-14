#ifndef sphere_h
#define sphere_h

#include "point.h"
#include "ray.h"
#include "hitInfo.h"
#include "interval.h"
#include "material.h"

#include <vector>

class Ray;
class HitInfo;
class Material;

class Sphere {

public:

    Sphere();
    Sphere(Point origin, double radius, Material* m);

    Point get_origin();
    double get_radius();
    Material* get_material();

private:

    Point origin;
    double radius;
    Material* material;

};

bool ray_collide(Ray& r, Interval& interval, std::vector<Sphere>& spheres, HitInfo& hit);


#endif
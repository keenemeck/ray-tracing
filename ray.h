#ifndef ray_h
#define ray_h

#include "vec3.h"
#include "point.h"
#include "color.h"
#include "hitInfo.h"
#include "rand.h"
#include "sphere.h"
#include "material.h"

#include <vector>

class Sphere;
class Material;

class Ray {

friend Color ray_color(Ray& r, std::vector<Sphere>& spheres, int bounces);

public:

    Ray();
    Ray(Point origin, Vector direction);

    Point pt(double time);

    Point get_origin();
    Vector get_direction();

private:

    Point origin;
    Vector direction;

};

#endif
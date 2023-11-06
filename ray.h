#ifndef ray_h
#define ray_h

#include "vec3.h"
#include "point.h"
#include "color.h"

class Ray {

friend Color ray_color(Ray& r);

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
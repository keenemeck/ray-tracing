#include "sphere.h"

#include <iostream>

Sphere::Sphere() : origin({0, 0, 0}), radius(0) {}
Sphere::Sphere(Point _origin, double _radius) : origin(_origin), radius(_radius) {}

Point Sphere::get_origin() { return origin; }
double Sphere::get_radius() { return radius; }

double Sphere::ray_collide(Ray& r) {

    Vector a_minus_c = (r.get_origin() - origin).to_vector();

    double a = r.get_direction().dot(r.get_direction());
    double h = r.get_direction().dot(a_minus_c);
    double c = a_minus_c.dot(a_minus_c) - radius * radius;

    double discrim = h * h - a * c;

    return discrim < 0 ? -1 : (-h - sqrt(discrim)) / a;

}
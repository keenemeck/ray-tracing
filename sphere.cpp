#include "sphere.h"

#include <iostream>

Sphere::Sphere() : origin({0, 0, 0}), radius(0) {}
Sphere::Sphere(Point _origin, double _radius) : origin(_origin), radius(_radius) {}

Point Sphere::get_origin() { return origin; }
double Sphere::get_radius() { return radius; }

bool Sphere::ray_collide(Ray& r, Interval& interval, HitInfo& hit) {

    Vector a_minus_c = (r.get_origin() - origin).to_vector();

    double a = r.get_direction().dot(r.get_direction());
    double h = r.get_direction().dot(a_minus_c);
    double c = a_minus_c.dot(a_minus_c) - radius * radius;

    double discrim = h * h - a * c;

    if (discrim < 0) return false;

    double discrim_sqrt = sqrt(discrim);

    double t = (-h - sqrt(discrim)) / a;

    if (t < interval.get_min() || t > interval.get_max()) {
        t = (-h + sqrt(discrim)) / a;
        if (t < interval.get_min() || t > interval.get_max()) return false;
    }

    Point p = r.pt(t);
    Vector n = (p - origin).to_vector().unit();

    hit.set_point(p);
    hit.set_t(t);

    if (r.get_direction().dot(n) > 0) {
        hit.set_front(true);
        n = -n;
        
    } else hit.set_front(false);
    
    hit.set_normal(n);

    return true;

}
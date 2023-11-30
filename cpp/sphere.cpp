#include "sphere.h"

#include <iostream>

Sphere::Sphere() : origin({0, 0, 0}), radius(0) {}
Sphere::Sphere(Point _origin, double _radius, Material* _material) : origin(_origin), radius(_radius), material(_material) {}

Point Sphere::get_origin() { return origin; }
double Sphere::get_radius() { return radius; }
Material* Sphere::get_material() {return material; }

bool ray_collide(Ray& r, Interval& interval, std::vector<Sphere>& spheres, HitInfo& closest_hit) {

    HitInfo hit;
    bool collide = false;

    for (auto& sphere: spheres) {      
    
        Vector a_minus_c = (r.get_origin() - sphere.get_origin()).to_vector();

        double a = r.get_direction().dot(r.get_direction());
        double h = r.get_direction().dot(a_minus_c);
        double c = a_minus_c.dot(a_minus_c) - sphere.get_radius() * sphere.get_radius();

        double discrim = h * h - a * c;

        // 1 or 2 roots exist
        if (discrim >= 0) {

            double discrim_sqrt = sqrt(discrim);

            double t = (-h - sqrt(discrim)) / a;

            // if first root out of range, try second root
            if (t <= interval.get_min() || t >= interval.get_max()) t = (-h + sqrt(discrim)) / a;

            if (t > interval.get_min() && t < interval.get_max()) {

                collide = true;

                Point p = r.pt(t);
                Vector n = (p - sphere.get_origin()).to_vector() / sphere.get_radius();

                hit.set_point(p);
                hit.set_t(t);

                hit.set_material(sphere.get_material());

                if (r.get_direction().dot(n) < 0) {
                    hit.set_front(true);
                } else {
                    hit.set_front(false);
                    n = -n;
                }

                hit.set_normal(n);

                if (hit.get_t() < closest_hit.get_t()) {
                    closest_hit = hit;
                }
            }

        }
    }

    return collide;

}
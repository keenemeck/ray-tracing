#include "ray.h"

Ray::Ray() : origin({0, 0, 0}), direction({0, 0, 0}) {}
Ray::Ray(Point _origin, Vector _direction) : origin(_origin), direction(_direction) {}

Point Ray::pt(double time) {
    return origin + (direction * time).to_point();
}

Point Ray::get_origin() { return origin; }

Vector Ray::get_direction() { return direction; }

Color ray_color(Ray& r, std::vector<Sphere>& spheres, int bounces) {

    Interval interval(0.01, INFINITY);
    HitInfo hit;

    if (ray_collide(r, interval, spheres, hit)) {
        
        Vector n = hit.get_normal();
        Vector direction = n + random_unit_vector();

        Ray new_ray(hit.get_point(), direction);

        if (bounces <= 0) return Color(0, 0, 0);

        return ray_color(new_ray, spheres, bounces - 1) * 0.1;
        
    }

    Vector unit_vector = r.get_direction().unit();

    double a = unit_vector.get_j() / 2 + 0.5;

    Color c1(90, 183, 230);
    Color c2(255, 255, 255);

    double blendedRed = (1 - a) * c2.get_r() + a * c1.get_r();
    double blendedGreen = (1 - a) * c2.get_g() + a * c1.get_g();
    double blendedBlue = (1 - a) * c2.get_b() + a * c1.get_b();

    return {blendedRed, blendedGreen, blendedBlue};

}
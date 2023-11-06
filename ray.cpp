#include "ray.h"

Ray::Ray() : origin({0, 0, 0}), direction({0, 0, 0}) {}
Ray::Ray(Point _origin, Vector _direction) : origin(_origin), direction(_direction) {}

Point Ray::pt(double time) {
    return origin + (direction * time).to_point();
}

Point Ray::get_origin() { return origin; }

Vector Ray::get_direction() { return direction; }

Color ray_color(Ray& r) {

    double a = r.get_direction().get_j() / 2 + 0.5;

    double blendedRed = (1 - a) * 120.0 + a * 206.0;
    double blendedGreen = (1 - a) * 47.0 + a * 184.0;
    double blendedBlue = (1 - a) * 64.0 + a * 136.0;

    return {round(blendedRed), round(blendedGreen), round(blendedBlue)};

}
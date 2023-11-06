#include "ray.h"

Ray::Ray() : origin({0, 0, 0}), direction({0, 0, 0}) {}
Ray::Ray(Point _origin, Vector _direction) : origin(_origin), direction(_direction) {}

Point Ray::pt(double time) {
    return origin + (direction * time).to_point();
}

Point Ray::get_origin() { return origin; }

Vector Ray::get_direction() { return direction; }

Color ray_color(Ray& r) {

    Vector unit_vector = r.get_direction().unit();

    double a = unit_vector.get_j() / 2 + 0.5;

    double redStart = 90, redEnd = 255;
    double greenStart = 183, greenEnd = 255;
    double blueStart = 230, blueEnd = 255;

    int blendedRed = (1 - a) * redEnd + a * redStart;
    int blendedGreen = (1 - a) * greenEnd + a * greenStart;
    int blendedBlue = (1 - a) * blueEnd + a * blueStart;

    return {blendedRed * 1.0, blendedGreen * 1.0, blendedBlue * 1.0};

}
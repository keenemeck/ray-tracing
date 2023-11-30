#include "ray.h"

Ray::Ray() {}
Ray::Ray(Point _origin, Vector _direction) : origin(_origin), direction(_direction) {}

Point Ray::pt(double time) {
    return origin + (direction * time).to_point();
}

Point Ray::get_origin() { return origin; }

Vector Ray::get_direction() { return direction; }

Color ray_color(Ray& r, std::vector<Sphere>& spheres, int bounces) {

    if (bounces <= 0) return Color(0, 0, 0);

    Interval interval(0.001, INFINITY);
    HitInfo hit;

    if (ray_collide(r, interval, spheres, hit)) {
        
        Ray scattered;
        Color attenuation;

        //return Color((hit.get_normal().get_i() + 1) * 127.5, (hit.get_normal().get_j() + 1) * 127.5, (hit.get_normal().get_k() + 1) * 127.5);

        // if hit object scatters light
        if (hit.get_material()->scatter(r, hit, attenuation, scattered)) {
            return ray_color(scattered, spheres, bounces - 1) * attenuation;
        }

        return Color(0,0,0);
        
    }

    Vector unit_vector = r.get_direction().unit();

    double a = unit_vector.get_j() / 2 + 0.5;

    Color c1(127.5, 178.5, 255);
    Color c2(255, 255, 255);

    double blendedRed = (1 - a) * c2.get_r() + a * c1.get_r();
    double blendedGreen = (1 - a) * c2.get_g() + a * c1.get_g();
    double blendedBlue = (1 - a) * c2.get_b() + a * c1.get_b();

    return {blendedRed, blendedGreen, blendedBlue};

}
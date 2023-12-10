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

    // Change background color here
    if (!ray_collide(r, interval, spheres, hit)) {


        // Vector a = r.get_direction().unit();
        // return Color((a.get_i() + 1) * 127.5, (a.get_j() + 1) * 127.5, (a.get_k() + 1) * 127.5);

        return Color(0, 0, 0);

    }
        
    Ray scattered;
    Color attenuation;

    Color emit_color = hit.get_material()->emitted();

    if (!hit.get_material()->scatter(r, hit, attenuation, scattered)) {
        return emit_color;
    }

    Color scatter_color = ray_color(scattered, spheres, bounces - 1) * attenuation;

    return emit_color + scatter_color;

}
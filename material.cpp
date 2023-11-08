#include "material.h"

Diffuse::Diffuse(Color _a) : albedo(_a) {}

Color Diffuse::get_albedo() { return albedo; }

bool Diffuse::scatter(Ray& ray, HitInfo& hit, Color& attenuation, Ray& scattered_ray) {

    Vector scatter_direction = hit.get_normal() + random_unit_vector();

    if (scatter_direction.near_zero()) scatter_direction = hit.get_normal();

    scattered_ray = Ray(hit.get_point(), scatter_direction);
    attenuation = get_albedo();
    return true;

}
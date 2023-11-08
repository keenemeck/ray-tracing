#include "material.h"

Material::Material() : albedo({255, 255, 255}), reflective(0) {}
Material::Material(Color _albedo) : albedo(_albedo), reflective(0) {}
Material::Material(Color _albedo, bool _reflective) : albedo(_albedo), reflective(_reflective) {}

bool Material::scatter(Ray& r, HitInfo& hit, Color& attenuation, Ray& scattered) {

    if (hit.get_material()->reflective) {

        Vector reflected_direction = r.get_direction().unit().reflect(hit.get_normal());
        scattered = Ray(hit.get_point(), reflected_direction);

    } else {

        Vector scatter_direction = hit.get_normal() + random_unit_vector();

        if (scatter_direction.near_zero()) scatter_direction = hit.get_normal();

        scattered = Ray(hit.get_point(), scatter_direction);

    }

    attenuation = albedo;
    return true;

}

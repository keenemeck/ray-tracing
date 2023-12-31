#include "material.h"

Material::Material() : albedo(Color(255, 255, 255)), reflective(false), refraction_index(1) {}
Material::Material(Color _albedo) : albedo(_albedo), reflective(false), refraction_index(1) {}
Material::Material(Color _albedo, bool _reflective) : albedo(_albedo), reflective(_reflective), fuzz(0), refraction_index(1) {}
Material::Material(Color _albedo, bool _reflective, double _fuzz) : albedo(_albedo), reflective(_reflective), fuzz(_fuzz), refraction_index(1) {}
Material::Material(double _refraction_index) : albedo(Color(255, 255, 255)), reflective(false), refraction_index(_refraction_index) {}
Material::Material(double _refraction_index, Color _albedo) : albedo(_albedo), reflective(false), refraction_index(_refraction_index) {}
Material::Material(bool _emissive, Color _albedo) : emissive(_emissive), albedo(_albedo) {}

Color Material::get_albedo() { return albedo; }
bool Material::get_reflective() { return reflective; }
double Material::get_fuzz() { return fuzz; }
double Material::get_refraction_index() { return refraction_index; }
bool Material::get_emissive() { return emissive; }

bool Material::scatter(Ray& r, HitInfo& hit, Color& attenuation, Ray& scattered) {

    if (reflective) {

        Vector reflected_direction = r.get_direction().unit().reflect(hit.get_normal());
        scattered = Ray(hit.get_point(), reflected_direction + random_unit_vector() * fuzz);

        attenuation = albedo;
        return scattered.get_direction().dot(hit.get_normal()) > 0;

    }

    else if (emissive == true) {

        return false;
        
    }
    
    else if (refraction_index != 1) { 

        attenuation = albedo;

        double eta_ratio = hit.get_front() ? (1.0 / refraction_index) : refraction_index;

        Vector unit = r.get_direction().unit();

        double cos_theta = std::min(-unit.dot(hit.get_normal()), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

        double r0 = ((1.0 - eta_ratio) / (1.0 + eta_ratio)) * ((1.0 - eta_ratio) / (1.0 + eta_ratio));
        bool schlick_reflect = (r0 + (1.0 - r0) * pow((1.0 - cos_theta), 5)) > random_double();

        // reflect if schnell's law has no solution - otherwise refract
        Vector direction = (eta_ratio * sin_theta > 1.0 || schlick_reflect) ? unit.reflect(hit.get_normal()) : unit.refract(hit.get_normal(), eta_ratio);

        scattered = Ray(hit.get_point(), direction);
        return true;

    }

    Vector scatter_direction = hit.get_normal() + random_unit_vector();

    if (scatter_direction.near_zero()) scatter_direction = hit.get_normal();

    scattered = Ray(hit.get_point(), scatter_direction);

    attenuation = albedo;
    return true;


}

Color Material::emitted() { return emissive ? albedo : Color(0, 0, 0); }
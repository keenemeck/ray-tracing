#ifndef material_h
#define material_h

#include "color.h"
#include "ray.h"
#include "hitInfo.h"

class Ray;
class HitInfo;

class Material {

public:

    Material();
    Material(Color albedo);
    Material(Color albedo, bool reflective);
    Material(Color albedo, bool reflective, double fuzz);
    Material(double refraction_index);

    Color get_albedo();
    bool get_reflective();
    double get_fuzz();
    double get_refraction_index();

    bool scatter(Ray& r, HitInfo& hit, Color& attenuation, Ray& scattered);

private:

    Color albedo;
    bool reflective;
    double fuzz;
    double refraction_index;

};

#endif
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

    Color get_albedo();
    bool get_reflective();

    bool scatter(Ray& r, HitInfo& hit, Color& attenuation, Ray& scattered);

private:

    Color albedo;
    bool reflective;

};

#endif
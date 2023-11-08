#ifndef material_h
#define material_h

#include "hitInfo.h"
#include "color.h"
#include "ray.h"
#include "color.h"
#include "vec3.h"

class Ray;
class HitInfo;


class Diffuse {

public:

    Diffuse(Color a);

    bool scatter(Ray& ray, HitInfo& hit, Color& attenuation, Ray& scattered_ray);

    Color get_albedo();

private:

    Color albedo;

};



#endif
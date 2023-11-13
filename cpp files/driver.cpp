#include <iostream>
#include <vector>

#include "vec3.h"
#include "point.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "hitInfo.h"
#include "camera.h"
#include "rand.h"
#include "material.h"


int main() {

    Camera camera(16.0 / 9.0, 400, 50);

    std::vector<Sphere> spheres;

    Material white_metal(Color(255, 255, 255), true);
    Material diffuse(Color(120, 47, 64));
    Material ground(Color(204, 204, 204));
    Material metal_left(Color(66, 135, 245), true);
    Material metal_right(Color(215, 66, 245), true);

    Material red_metal(Color(255, 0, 0), true);
    Material green_metal(Color(0, 255, 0), true);
    Material blue_metal(Color(0, 0, 255), true);
    
    spheres.push_back({{0, 0, -1}, 0.5, &diffuse});
    spheres.push_back({{-1, 0, -1}, 0.5, &white_metal});
    spheres.push_back({{1, 0, -1}, 0.5, &white_metal});
    
    camera.render(spheres); 

    return 0;
    
}
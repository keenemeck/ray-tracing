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

    Camera camera(16.0 / 9.0, 720, 1000);

    std::vector<Sphere> spheres;

    Material white_metal(Color(255, 255, 255), true);
    Material diffuse(Color(120, 47, 64), false);
    Material ground(Color(204, 204, 204), false);
    Material metal_left(Color(66, 135, 245), true);
    Material metal_right(Color(215, 66, 245), true);

    // garnet:  (120, 47, 64)

    spheres.push_back({{0, 0, -.8}, 0.5, &ground});
    spheres.push_back({{-1, 0, -.7}, 0.5, &metal_left});
    spheres.push_back({{1, 0, -.7}, 0.5, &metal_right});
    spheres.push_back({{0, -100.5, -1}, 100, &ground});
    
    camera.render(spheres); 

    return 0;
    
}
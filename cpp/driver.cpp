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
#include "color.h"


int main() {

    Camera camera(16.0 / 9.0, 400, 10);

    std::vector<Sphere> spheres;

    Material white_metal(Color(255, 255, 255), true);
    Material garnet(Color(120, 47, 64));
    Material ground(Color(204, 204, 204));
    Material metal_left(Color(66, 135, 245), true, 0.7);
    Material metal_right(Color(215, 66, 245), true, 0.3);
    Material glass(1.5);
    Material red(Color(240, 17, 40));

    
    Material material_ground(Color(0.8*255, 0.8*255, 0.0*255));
    Material material_center(Color(17, 60, 246));
    Material material_left(1.5);
    Material material_right(Color(120, 47, 64), true, 0.01);

    
    spheres.push_back({{0, 0, -1}, -0.5, &material_center});
    spheres.push_back({{-1, 0, -1}, 0.5, &material_left});
    //spheres.push_back({{-1, 0, -1}, -0.4, &material_left});
    spheres.push_back({{1, 0, -1}, 0.5, &material_right});
    spheres.push_back({{0, -100.5, -1}, 100, &material_ground});
    
    camera.render(spheres); 

    return 0;
    
}
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


int main() {

    Camera camera(16.0 / 9.0, 400, 1000);

    std::vector<Sphere> spheres;

    spheres.push_back({{0, -0.5, -1}, 0.25});
    spheres.push_back({{0, 0, -1}, 0.25});
    spheres.push_back({{0, 0.5, -1}, 0.25});
    spheres.push_back({{-0.5, 0, -1}, 0.25});
    spheres.push_back({{0.5, 0, -1}, 0.25});
    spheres.push_back({{-0.5, -0.5, -1}, 0.25});
    spheres.push_back({{0.5, -0.5, -1}, 0.25});
    spheres.push_back({{-0.5, 0.5, -1}, 0.25});
    spheres.push_back({{0.5, 0.5, -1}, 0.25});
    
    camera.render(spheres); 

    return 0;
    
}
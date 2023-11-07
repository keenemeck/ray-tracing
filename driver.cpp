#include <iostream>
#include <vector>

#include "vec3.h"
#include "point.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "hitInfo.h"
#include "camera.h"


int main() {

    Camera camera(16.0 / 9.0, 400, 50);


    std::vector<Sphere> spheres;
    

    spheres.push_back({{0, 0, -1}, 0.5});

    spheres.push_back({{0, -100.5, -1}, 100});
    
    camera.render(spheres);


    return 0;
    
}
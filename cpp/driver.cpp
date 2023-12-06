#include <iostream>
#include <vector>
#include <chrono>

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

    /*  Camera(aspect ratio, image width, anti-aliasing samples) 
     *
     *  The aspect ratio refers to the ratio between the image width to the image height
     *  The image width is the width of the image in pixels
     *  The AA samples are the amount of rays drawn at each pixel, (higher number is more rays,
     *  which means a smoother result). 
     */

    // Default camera settings
    Camera camera(16.0 / 9.0, 400, 10);

    // List of spheres
    std::vector<Sphere> spheres;

    // Examples of materials
    Material material_ground(Color(204, 204, 0));
    Material material_center(Color(17, 60, 246));
    Material material_left(1.5);
    Material material_right(Color(120, 47, 64), true);

    // Adding spheres to scene with coordinates
    spheres.push_back({{-1, 0, -1}, 0.5, &material_left});
    spheres.push_back({{-3, 0, -3}, 0.5, &material_left});
    spheres.push_back({{0, 0, -1}, 0.5, &material_center});
    spheres.push_back({{1, 0, -1}, 0.5, &material_right});
    spheres.push_back({{0, -100.5, -1}, 100, &material_ground});
    
    auto start = std::chrono::high_resolution_clock::now();
    camera.render(spheres); 
    auto stop = std::chrono::high_resolution_clock::now();

    std::clog << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000000.0;

    return 0;
    
}
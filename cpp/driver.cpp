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
#include "aabb.h"
#include "objects.h"

int main() {

    /*  Camera(aspect ratio, image width, anti-aliasing samples) 
     *
     *  The aspect ratio refers to the ratio between the image width to the image height
     *  The image width is the width of the image in pixels
     *  The AA samples are the amount of rays drawn at each pixel, (higher number is more rays,
     *  which means a smoother result). 
     */

    // Default camera settings
    Camera camera(16.0 / 9.0, 400, 500);

    objectList objects;

    // Examples of materials
    Material ground(Color(204, 204, 204));
    Material blueDiffuse(Color(17, 60, 246));
    Material orangeDiffuse(Color(246, 60, 17));
    Material light(true, Color(245, 242, 213));
    Material reflect(Color(255, 255, 255), true);
    Material glass(1.5);
    

    // Adding spheres to scene with coordinates
    objects.add({{0, 30, -10}, 20, &light});
    objects.add({{-1, 0, -1}, 0.5, &blueDiffuse});
    objects.add({{0, 0, -1}, 0.5, &reflect});
    objects.add({{1, 0, -1}, 0.5, &glass});
    objects.add({{0, -100.5, -1}, 100, &ground});
    
    auto start = std::chrono::high_resolution_clock::now();
    camera.render(objects.get_spheres()); 
    auto stop = std::chrono::high_resolution_clock::now();

    std::clog << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000000.0;

    return 0;
    
}
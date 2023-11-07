#ifndef camera_h
#define camera_h

#include "vec3.h"
#include "point.h"
#include "color.h"
#include "sphere.h"
#include "ray.h"
#include "rand.h"

#include <vector>

class Camera {

public:

    Camera();
    Camera(double ratio, int height, int samples);

    void initialize();
    void render(std::vector<Sphere>& spheres);

    Ray get_ray(int i, int j);

private:

    double aspect_ratio, focal_length, viewport_height;
    int image_height, image_width, samples;
    Point pixel_00, camera_center;
    Vector du, dv;

};

#endif
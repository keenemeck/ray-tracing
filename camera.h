#ifndef camera_h
#define camera_h

#include "vec3.h"
#include "point.h"
#include "color.h"
#include "sphere.h"

#include <vector>

class Camera {

public:

    Camera();

    void initialize();
    void render(std::vector<Sphere>& spheres);

private:

    double aspect_ratio, focal_length, viewport_height;
    int image_height, image_width;
    Point pixel_00, camera_center;
    Vector du, dv;

};


#endif
#include <iostream>

#include "vec3.h"
#include "point.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"


int main() {

    double aspect_ratio = 16.0 / 9.0;

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * aspect_ratio;

    int image_height = 400;
    int image_width = image_height * aspect_ratio;

    Vector Vu(viewport_width, 0, 0);
    Vector Vv(0, -viewport_height, 0);


    Point camera_center(0, 0, 0);

    Vector du = Vu / image_width;
    Vector dv = Vv / image_height;

    Point viewport_q = camera_center - Point(viewport_width / 2, -viewport_height / 2, focal_length);

    Point pixel_00 = viewport_q + (du / 2).to_point() + (dv / 2).to_point();

    Sphere sphere({0, 0, -1}, 0.5);

    // Draw ppm
    std::cout << "P3\n" << image_width << ' ' << image_height << '\n' << 255 << '\n';

    for (int i = 0; i < image_height; i++) {

        std::clog << image_height - i << " rows remaining.\n";

        for (int j = 0; j < image_width; j++) {  

            Point pixel_center = pixel_00 + (du * j).to_point() + (dv * i).to_point();
            Vector direction = (pixel_center - camera_center).to_vector();
            Ray ray(camera_center, direction);

            double t = sphere.ray_collide(ray);

            

            Color color = {125, 94, 23};

            if (t != -1) {
                Vector normal = ((ray.pt(t) - sphere.get_origin()).to_vector()).unit();
                color = {round((normal.get_i() + 1) * 127.5), round((normal.get_j() + 1) * 127.5), round((normal.get_k() + 1) * 127.5)};
            } else color = ray_color(ray);
            
            std::cout << color;

        }

        std::cout << '\n';
    }

    std::clog << "Done.\n";


    return 0;
    
}
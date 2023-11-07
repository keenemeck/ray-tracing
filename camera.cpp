#include "camera.h"

Camera::Camera() : aspect_ratio(16.0 / 9.0), focal_length(1.0), viewport_height(2.0), image_height(400) {}

void Camera::initialize() {

    double viewport_width = viewport_height * aspect_ratio;
    image_width = image_height * aspect_ratio;

    Vector Vu(viewport_width, 0, 0);
    Vector Vv(0, -viewport_height, 0);

    du = Vu / image_width;
    dv = Vv / image_height;

    camera_center = {0, 0, 0};

    Point viewport_q = camera_center - Point(viewport_width / 2, -viewport_height / 2, focal_length);

    pixel_00 = viewport_q + (du / 2).to_point() + (dv / 2).to_point();

}

void Camera::render(std::vector<Sphere>& spheres) {

    initialize();

    Interval interval(0, INFINITY);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++) {

        std::clog << image_height - i << " rows remaining.\n";

        for (int j = 0; j < image_width; j++) {  

            Point pixel_center = pixel_00 + (du * j).to_point() + (dv * i).to_point();
            Vector direction = (pixel_center - camera_center).to_vector();
            Ray ray(camera_center, direction);

            HitInfo hit;
            HitInfo closest_hit;

            for (auto sphere: spheres) {

                bool collide = sphere.ray_collide(ray, interval, hit);

                if (collide && hit.get_t() < closest_hit.get_t()) closest_hit = hit;
                
            }

            Color color = ray_color(ray, closest_hit);
            std::cout << color;

        }

        std::cout << '\n';
    }

    std::clog << "Done.\n";

}
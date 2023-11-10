#include "camera.h"

Camera::Camera() : aspect_ratio(16.0 / 9.0), image_height(400), samples(100) {}
Camera::Camera(double ratio, int height, int _samples) : aspect_ratio(ratio), image_height(height), samples(_samples) {}

void Camera::initialize() {

    focal_length = 1.0;
    viewport_height = 2.0;
    bounces = 20;

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

        std::clog << (i * 100.0) / image_height << "%\n";

        for (int j = 0; j < image_width; j++) {  

            Color color;

            for (int k = 0; k < samples; k++) {

                Ray ray = get_ray(i, j);

                Color temp = ray_color(ray, spheres, bounces);

                color = color + temp;

            }

            color.write_color(std::cout, samples);

        }

        std::cout << '\n';
    }

    std::clog << "100%\n";

}

Ray Camera::get_ray(int i, int j) {

    Vector sampleOffset = du * (-0.5 + random_double()) + dv * (-0.5 + random_double());
    Point pixel_center = pixel_00 + (du * j).to_point() + (dv * i).to_point();

    Point pixel_sample = sampleOffset.to_point() + pixel_center;

    return Ray(camera_center, (pixel_sample - camera_center).to_vector());

}
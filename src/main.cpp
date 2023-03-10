#include "ray.h"
#include <fstream>

vec3 convert_to_color(ray r) {
    vec3 unit_vector = r.get_direction().make_unit();
    float t = 0.5*(1 + unit_vector.get_y());
    return (1-t)*vec3(1, 1, 1) + t*vec3(0.3, 0.6, 1);
}

int main() {
    std::ofstream file;
    file.open("Image2.ppm");

    int width = 200;
    int height = 100;
    int distance = 100;
    float u, v;
    vec3 color;
    int ir, ig, ib;

    file << "P3\n" << width << " " << height << "\n255\n";

    vec3 horizontal        = vec3(width, 0, 0);
    vec3 vertical          = vec3(0, height, 0);
    vec3 origin            = vec3(0, 0, 0);
    vec3 lower_left_corner = vec3(-width/2, -height/2, -distance); 

    for (double j = height-1; j >= 0; j--) {
        for (double i = 0; i < width; i++) {
            u = i/width;
            v = j/height;
            ray fired_ray = ray(origin, lower_left_corner + u*horizontal + v*vertical);

            color = convert_to_color(fired_ray);
            ir = 255*color.get_x();
            ig = 255*color.get_y();
            ib = 255*color.get_z();
            file << ir << " " << ig << " " << ib << "\n";
        }
    }

    file.close();

    return 0;
}
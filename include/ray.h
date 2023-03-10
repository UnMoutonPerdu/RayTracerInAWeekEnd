#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        vec3 init_point;
        vec3 direction;

        ray() {vec3 point; vec3 dir; this->init_point = point; this->direction = dir; }
        ray(const vec3 &point, const vec3 &dir) { this->init_point = point; this->direction = dir; }
        inline vec3 get_init_point() const { return this->init_point; }
        inline vec3 get_direction() const { return this->direction; }
        inline vec3 translation(float t) const { return this->init_point + this->direction*t; }
};


#endif
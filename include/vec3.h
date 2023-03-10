#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdexcept>

class vec3 {
    private:
        // Coordinates
        float x, y, z;
    public:
        // Constructors
        vec3() { x = y = z = 0; }
        vec3(float a, float b, float c) { x = a; y = b; z = c; }

        // Getters
        inline float get_x() const { return x; }
        inline float get_y() const { return y; }
        inline float get_z() const { return z; }

        // Redifining operators
        inline vec3 operator+(const vec3 &u) const { return vec3(this->x + u.x, this->y + u.y, this->z + u.z); }
        inline vec3 operator-(const vec3 &u) const { return vec3(this->x - u.x, this->y - u.y, this->z - u.z); }
        inline vec3 operator-() const { return vec3(-this->x, -this->y, -this->z); }
        inline vec3 operator*(const vec3 &u) const { return vec3(this->x * u.x, this->y * u.y, this->z * u.z); }
        inline vec3 operator*(float t) const { return vec3(this->x * t, this->y * t, this->z * t); }
        inline vec3 operator/(const vec3 &u) const { 
            if (u.x == 0.0 || u.y == 0.0 || u.z == 0.0) {
                throw std::invalid_argument("Coordinates can't be zero for the division operator");
            }
            return vec3(this->x / u.x, this->y / u.y, this->z / u.z); }
        inline vec3 operator/(float t) const {
            if (t == 0.0) {
                throw std::invalid_argument("Can't divide by zero");
            }
            return vec3(this->x / t, this->y / t, this->z / t);
        }
        inline vec3& operator+=(const vec3 &u) {
            this->x += u.x;
            this->y += u.y;
            this->z += u.z;

            return *this;
        }
        inline vec3& operator-=(const vec3 &u) {
            this->x -= u.x;
            this->y -= u.y;
            this->z -= u.z;

            return *this;
        }
        inline vec3& operator*=(const vec3 &u) {
            this->x *= u.x;
            this->y *= u.y;
            this->z *= u.z;

            return *this;
        }
        inline vec3& operator*=(float t) {
            this->x *= t;
            this->y *= t;
            this->z *= t;
        
            return *this;
        }
        inline vec3& operator/=(const vec3 &u) {
            if (u.x == 0.0 || u.y == 0.0 || u.z == 0.0) {
                throw std::invalid_argument("Coordinates can't be zero for the division operator");
            }
            
            this->x /= u.x;
            this->y /= u.y;
            this->z /= u.z;

            return *this;
        }
        inline vec3& operator/=(float t) {
            if (t == 0) {throw std::invalid_argument("Can't divide by zero");}
            this->x /= t;
            this->y /= t;
            this->z /= t;

            return *this;
        }

        // Operators 
        inline float dot(const vec3 &u) const { return this->x*u.x + this->y*u.y + this->z*u.z; }
        inline vec3 cross(const vec3 &u) const { return vec3(this->y*u.z - this->z*u.y, this->z*u.x - this->x*u.z, this->x*u.y - this->y*u.x); }
        inline float length() const { return sqrt(this->x*this->x + this->y*this->y + this->z*this->z); }
        inline vec3& make_unit() { return (*this /= this->length()); }
};

inline vec3 operator*(float t, const vec3 &u) {
    return vec3(u.get_x() * t, u.get_y() * t, u.get_z() * t);
}

std::ostream& operator<<(std::ostream &os, const vec3 &vector) {
    os << vector.get_x() << " " << vector.get_y() << " " << vector.get_z();
    return os;
}
/* inline std::istream& operator>>(std::istream &is, const vec3 &vector) {
    is >> vector.x >> vector.y >> vector.z;
    return is;
} */

#endif
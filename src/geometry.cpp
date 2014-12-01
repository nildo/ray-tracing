#include "geometry.h"

using namespace std;

/**
 * Methods from Vector
 */

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector& Vector::operator=(const Vector& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector& Vector::operator+=(const Vector& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector& Vector::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Vector& Vector::operator/=(float f) {
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

float Vector::length() {
    return sqrt(x * x + y * y + z * z);
}

float Vector::normalize() {
    float len = length();
    *this /= len;
    return len;
}

Vector Vector::normalized() {
    Vector r(x, y, z);
    r.normalize();
    return r;
}

Vector operator+(const Vector& v1, const Vector& v2) {
    Vector r = Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return r;
}

Vector operator-(const Vector& v1, const Vector& v2) {
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}


Vector operator*(const Vector& v, float f) {
    return Vector(f * v.x, f * v.y, f * v.z);
}


Vector operator*(float f, const Vector& v) {
    return Vector(f * v.x, f * v.y, f * v.z);
}

ostream& operator<<(ostream& os, Vector& v) {
    os << "[" << v.x << "," << v.y << "," << v.z << "]";
    return os;
}

float dot(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector cross(const Vector& v1, const Vector& v2) {
    return Vector(v1.y * v2.z - v1.z * v2.y,
                  v1.z * v2.x - v1.x * v2.z,
                  v1.x * v2.y - v1.y * v2.x);
}
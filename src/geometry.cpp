#include "geometry.h"

using namespace std;

/**
 *  Methods from Point
 */

Point::Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

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

Vector operator+(const Vector& v1, const Vector& v2) {
    Vector r = Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return r;
}

ostream& operator<<(ostream& os, Vector& v) {
    os << "[" << v.x << "," << v.y << "," << v.z << "]";
    return os;
}

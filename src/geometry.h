#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <iostream>

#define PI 3.14159265358979

using namespace std;

/*class Point {
public:
    float x;
    float y;
    float z;

    Point();
    Point(float x, float y, float z);

    Point& operator=(const Point& p);
};

ostream& operator<<(ostream& os, Point& p);*/

class Vector {
public:
    float x;
    float y;
    float z;

    Vector();
    Vector(float x, float y, float z);

    Vector& operator=(const Vector& v);
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator*=(float f);
    Vector& operator/=(float f);

    float length();
    float normalize();
    Vector normalized();
};

Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v, float f);
Vector operator*(float f, const Vector& v);
ostream& operator<<(ostream& os, Vector& v);

float dot(const Vector& v1, const Vector& v2);
Vector cross(const Vector& v1, const Vector& v2);

typedef Vector Point;

#endif

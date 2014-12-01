#ifndef RAY_H
#define RAY_H

#include "geometry.h"

using namespace std;

class Ray {
public:
    Point origin;
    Vector direction;
    float tMax;

    Ray();
    Ray(Point origin, Vector direction, float tMax);
};

#endif
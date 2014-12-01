#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include "geometry.h"
#include "ray.h"

using namespace std;

class Camera {
public:
    Point origin, target, up;
    float opening;

    Camera();
    Camera(Point origin, Point target, Point up, float opening);

    Ray makeRay(float x, float y);

};

#endif
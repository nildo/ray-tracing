#ifndef CAMERA_H
#define CAMERA_H

#include "geometry.h"

class Camera {
public:
    Point origin, target, up;
    float opening;

    Camera();
    Camera(Point origin, Point target, Point up, float opening);

};

#endif
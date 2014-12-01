#include "camera.h"

Camera::Camera() {
}

Camera::Camera(Point origin, Point target, Point up, float opening) {
    this->origin = origin;
    this->target = target;
    this->up = up;
    this->opening = opening;
}
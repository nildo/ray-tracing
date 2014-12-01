#include "camera.h"

Camera::Camera() {
}

Camera::Camera(Point origin, Point target, Point up, float opening) {
    this->origin = origin;
    this->target = target;
    this->up = up;
    this->opening = opening;
}

Ray Camera::makeRay(float x, float y) {
    Vector forward = (target - origin).normalized();
    Vector right = cross(forward, up).normalized();
    up = up.normalized();

    float tanOp = tan(opening * PI / 180);
    Ray ray;
    ray.origin = origin;
    ray.direction = forward + right * ((x - 0.5) * tanOp) + up * ((y - 0.5) * tanOp);
    ray.direction.normalized();

    return ray;
}
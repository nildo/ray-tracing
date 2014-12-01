#include "ray.h"

Ray::Ray() {
}

Ray::Ray(Point origin, Vector direction, float tMax) {
    this->origin = origin;
    this->direction = direction;
    this->tMax = tMax;
}

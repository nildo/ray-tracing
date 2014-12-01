#include "object.h"

Object::Object(ObjectType t, Pigment p, Finishing f) {
    this->type = t;
    this->pigment = p;
    this->finishing = f;
}

Sphere::Sphere(Pigment p, Finishing f, float x, float y, float z, float r)
                : Object(SPHERE, p, f) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
}

Plane::Plane(float a, float b, float c, float d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

Polyhedron::Polyhedron(Pigment p, Finishing f) : Object(POLYHEDRON, p, f) {
}

void Polyhedron::addPlane(Plane p) {
    planes.push_back(p);
}

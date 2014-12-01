#include "object.h"

Object::Object() {
}

Object::Object(ObjectType t, Pigment p, Finishing f) {
    this->type = t;
    this->pigment = p;
    this->finishing = f;
}

Color Object::getColor(Point p) {
    // TODO: fix this. Have to consider the type of pigment.
    return pigment.color1;
}

Sphere::Sphere(Pigment p, Finishing f, float x, float y, float z, float r)
                : Object(SPHERE, p, f) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
}

bool Sphere::intersect(Ray r, Point& p) {
    return false;
}

Plane::Plane(float a, float b, float c, float d) : Object(){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

bool Plane::intersect(Ray r, Point& p) {
    return false;
}

Polyhedron::Polyhedron(Pigment p, Finishing f) : Object(POLYHEDRON, p, f) {
}

void Polyhedron::addPlane(Plane p) {
    p.pigment = pigment;
    p.finishing = finishing;
    planes.push_back(p);
}

bool Polyhedron::intersect(Ray r, Point& p) {
    return false;
}

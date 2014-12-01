#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "pigment.h"
#include "finishing.h"

using namespace std;

typedef enum objectType {
    SPHERE,
    POLYHEDRON
} ObjectType;

class Object {
public:
    ObjectType type;
    Pigment pigment;
    Finishing finishing;

    Object(ObjectType t, Pigment p, Finishing f);
};

class Sphere : public Object {
public:
    float x, y, z, r;

    Sphere(Pigment p, Finishing f, float x, float y, float z, float r);
};

class Plane {
public:
    float a, b, c, d;

    Plane(float a, float b, float c, float d);
};

class Polyhedron : public Object {
public:
    vector<Plane> planes;

    Polyhedron(Pigment p, Finishing f);

    void addPlane(Plane p);
};

#endif

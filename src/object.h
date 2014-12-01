#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "pigment.h"
#include "finishing.h"
#include "geometry.h"
#include "ray.h"

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

    Object();
    Object(ObjectType t, Pigment p, Finishing f);

    virtual bool intersect(Ray r, Point& p) = 0;
    Color getColor(Point p);
};

class Sphere : public Object {
public:
    float x, y, z, r;

    Sphere(Pigment p, Finishing f, float x, float y, float z, float r);

    bool intersect(Ray r, Point& p);
};

class Plane : public Object{
public:
    float a, b, c, d;

    Plane(float a, float b, float c, float d);

    bool intersect(Ray r, Point& p);
};

class Polyhedron : public Object {
public:
    vector<Plane> planes;

    Polyhedron(Pigment p, Finishing f);

    void addPlane(Plane p);
    bool intersect(Ray r, Point& p);
};

#endif

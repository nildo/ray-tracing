#include <iostream>

using namespace std;

class Point {
public:
    float x;
    float y;
    float z;

    Point();
    Point(float x, float y, float z);
};

class Vector {
public:
    float x;
    float y;
    float z;

    Vector();
    Vector(float x, float y, float z);
};

Vector operator+(const Vector& v1, const Vector& v2);
ostream& operator<<(ostream& os, Vector& v);

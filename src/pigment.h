#ifndef PIGMENT_H
#define PIGMENT_H

#include "color.h"

typedef enum pigmentType {
    SOLID,
    CHECKER,
    TEXMAP
} PigmentType;

class Texmap {
public:
    // TODO: implement this.
};

class Pigment {
public:
    PigmentType type;
    Color color1, color2;
    float length;
    Texmap texture;

    Pigment();
    Pigment(Color color);
    Pigment(Color c1, Color c2, float l);
    Pigment(Texmap tm);

};

ostream& operator<<(ostream& os, Pigment& p);

#endif

#ifndef PIGMENT_H
#define PIGMENT_H

#include "color.h"

typedef enum pigmentType {
    SOLID,
    CHECKER,
    TEXTMAP
} PigmentType;

class Textmap {
public:
    // TODO: implement this.
};

class Pigment {
public:
    PigmentType type;
    Color color1, color2;
    float length;
    Textmap texture;

    Pigment();
    Pigment(Color color);
    Pigment(Color c1, Color c2, float l);
    Pigment(Textmap tm);

};

ostream& operator<<(ostream& os, Pigment& p);

#endif

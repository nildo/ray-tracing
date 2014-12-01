#ifndef LIGHT_H
#define LIGHT_H

#include "color.h"
#include "geometry.h"

typedef enum type_of_light {
    AMBIENT,
    SOURCE
} LightType;

class Light {
public:
    LightType type;
    Point location;
    Color color;
    float ac; // Attenuation Constant
    float ad; // Attenuation proportional to the Distance
    float as; // Attenuation proportional to the distance Squared

    Light();
    Light(LightType type, Point location, Color color, float ac, float ad, float as);
};

ostream& operator<<(ostream& os, Light& l);

#endif
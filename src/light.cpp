#include "light.h"

Light::Light() {

}

Light::Light(LightType type, Point location, Color color, float ac, float ad, float as) {
    this->type = type;
    this->location = location;
    this->color = color;
    this->ac = ac;
    this->ad = ad;
    this->as = as;
}

ostream& operator<<(ostream& os, Light& l) {
    os << l.type << ' ' << l.location << ' ' << l.color << ' '
       << l.ac << ' ' << l.ad << ' ' << l.as << endl;
    return os;
}
#include "pigment.h"

Pigment::Pigment() {
}

Pigment::Pigment(Color color) {
    this->type = SOLID;
    this->color1 = color;
}
Pigment::Pigment(Color c1, Color c2, float l) {
    this->type = CHECKER;
    this->color1 = c1;
    this->color2 = c2;
    this->length = l;
}
Pigment::Pigment(Textmap tm) {
    this->type = TEXTMAP;
    this->texture = tm;
}

ostream& operator<<(ostream& os, Pigment& p) {
    switch (p.type) {
        case SOLID:
            cout << p.type << " solid " << p.color1;
        break;
        case CHECKER:
            cout << p.type << " checker " << p.color1 << ' ' << p.color2 << ' ' << p.length;
        break;
        case TEXTMAP:
            cout << p.type << " textmap ";
        break;
    }
    return os;
}
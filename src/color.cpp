#include "color.h"

using namespace std;

Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

ostream& operator<<(ostream& os, Color& c) {
    int r = c.r * 255;
    int g = c.g * 255;
    int b = c.b * 255;
    os << r << ' ' << g << ' ' << b;
    return os;
}
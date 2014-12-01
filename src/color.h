#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using namespace std;

class Color {
public:
    float r, g, b;

    Color();
    Color(float r, float g, float b);

};

ostream& operator<<(ostream& os, Color& c);

#endif
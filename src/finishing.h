#ifndef FINISHING_H
#define FINISHING_H

#include <iostream>

using namespace std;

class Finishing {
public:
    float ka; // Ambient light coeficient
    float kd; // Difuse light coeficient
    float ks; // Specular light coeficient
    float alpha; // Specular reflection exponent
    float kr; // > 0 reflects the light
    float kt; // > 0 transmits light
    float ior; // Snell law

    Finishing();
    Finishing(float ka, float kd, float ks, float alpha,
              float kr, float kt, float ior);
};

ostream& operator<<(ostream& os, Finishing& f);

#endif

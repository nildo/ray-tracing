#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "color.h"

using namespace std;

class Pixel {
public:
    int x, y;
    Color color;
};

class Image {
public:
    int width, height;
    Pixel **pixels;

    Image(int width, int height);
    Image(int width, int height, Color color);
    ~Image();

    void print(ostream& file);
};


#endif